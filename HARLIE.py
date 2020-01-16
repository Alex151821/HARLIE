import discord
from discord.ext import commands
import os
from keep_alive import keep_alive
from datetime import datetime as dt
import time
import random
import youtube_dl

client = commands.Bot(command_prefix = ':')

@client.event
async def on_ready():
  print("I'm in")
  print(client.user)
  

@client.event
async def on_message(message):
  
  print()
  file = open('conversations.txt', 'a')
  print(message.author)
  print(message.channel.name)
  print(message.content)
  file.write('Author = '+ str(message.author))
  file.write('| Channel = '+ str(message.channel.name))
  file.write('| Said: ' + str(message.content))
  file.write('| At: ' + str(dt.now()) + '\n')
  file.close()
  await client.process_commands(message)

@client.command()
async def say(ctx):
  a = ctx.message.content.split(" ")
  a.remove(':say')
  await ctx.send(" ".join(a))

@client.command()
async def roll(ctx):
  message_content = ctx.message.content.split(' ')
  a = message_content[1].lower().split("d")
  print (a)
  b = []
  final = []
  a[0] = int(a[0])
  a[1] = int(a[1])
  for i in range(0, a[0]):
    for j in range(0, 5):
      b.append(random.randint(0, a[1]))
      print(b)
    final.append(b[random.randint(0, 5)])
    print (message_content[1])
  await ctx.send("Final results for " + str(message_content[1]) +": " + " ".join(map(str, final)))

  """
    a = []
    b = []
    final = []
    for i in message_content[2]:
      a.append(i)
    try:
      if a[3]:
        a[2] = int(a[2])
        a[2] = a[2]*10
        a[2] = a[2] + int(a[3])
        a.pop(3)
    except:
      pass
      

    for i in range(0, int(a[0])):
      for i in range(0, 5):
        b.append(random.randint(0, int(a[2])))
      final.append(str(b[random.randint(0, 4)]))
    """

@client.command()
async def join(ctx):
  channel = ctx.message.author.voice.channel
  await channel.connect()

@client.command()
async def leave(ctx):
  await ctx.voice_client.disconnect()
"""
@client.command()
async def play(ctx, url):
  server = ctx.message.server
"""
  


keep_alive()
token = os.environ.get('DISCORD_BOT_SECRET')
client.run(token)