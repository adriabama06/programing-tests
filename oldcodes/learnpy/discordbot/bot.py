import discord
import json
import youtube_dl
import asyncio

import Servers
from CommandsManager import Commands

cmds = Commands()

import cmds.testtest as testtest

cmds.add('test', testtest)
cmds.addAlias(['example', 'cmd2'], 'test')

servers = Servers.Servers()

configFile = open('config.json')
config = json.load(configFile)

client = discord.Client()

ytdl_format_options = {
    'format': 'bestaudio/best',
    'quality': 'highestaudio',
    'filter': 'audioonly',
    'outtmpl': '%(extractor)s-%(id)s-%(title)s.%(ext)s',
    'restrictfilenames': True,
    'noplaylist': True,
    'nocheckcertificate': True,
    'ignoreerrors': False,
    'logtostderr': False,
    'quiet': True,
    'no_warnings': True,
    'default_search': 'auto',
    'source_address': '0.0.0.0' # bind to ipv4 since ipv6 addresses cause issues sometimes
}

ffmpeg_options = {
    'before_options': '-reconnect 1 -reconnect_streamed 1 -reconnect_delay_max 5',
    'options': '-vn'
}

ytdl = youtube_dl.YoutubeDL(ytdl_format_options)


class YTDLSource(discord.PCMVolumeTransformer):
    def __init__(self, source, *, data, volume=1):
        super().__init__(source, volume)

        self.data = data

        self.title = data.get('title')
        self.url = data.get('url')

    @classmethod
    async def from_url(cls, url, *, loop=None, stream=False):
        loop = loop or asyncio.get_event_loop()
        data = await loop.run_in_executor(None, lambda: ytdl.extract_info(url, download=not stream))

        if 'entries' in data:
            # take first item from a playlist
            data = data['entries'][0]

        filename = data['url'] if stream else ytdl.prepare_filename(data)
        return cls(discord.FFmpegPCMAudio(filename, **ffmpeg_options), data=data)

@client.event
async def on_ready():
    print(f'Iniciado como: {client.user}')

@client.event
async def on_message(message: discord.Message):
    if message.author == client.user or not message.content.startswith(config['prefix']):
        return

    guildid = str(message.guild.id)

    if not servers.has(guildid):
        servers.add(guildid)

    server = servers.get(guildid)

    args = message.content[len(config['prefix']):].split(" ")
    
    cmd = args.pop(0).lower()

    if cmds.has(cmd):
        cmds.get(cmd).run(message, cmd, args, config['prefix'], server)
        return
    if cmds.hasAlias(cmd):
        cmds.getAlias(cmd).run(message, cmd, args, config['prefix'], server)
        return
    message.channel.send(f'Commando desconozido: {cmd}')
    return

client.run(config['token'])