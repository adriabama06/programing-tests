import discord
import bot

async def run(message: discord.Message, cmd: str, args: list, prefix: str, server: bot.Servers):
    await message.channel.send('test!')
    return