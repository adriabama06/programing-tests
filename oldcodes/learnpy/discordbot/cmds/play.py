import discord
import bot

cmd = 'play'

alias = ['p', 'inicia']

async def run(message: discord.Message, cmd: str, args: list, prefix: str, server: bot.Servers):
    if not server['connection']:
        server['connection'] = await message.author.voice.channel.connect()
    if message.author.voice.channel:
        player = await bot.YTDLSource.from_url(args[0], stream=True)
        server['connection'].play(player, after=lambda e: print(f'Player error: {e}') if e else None)
    return