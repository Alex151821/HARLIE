import discord
import os
from keep_alive import keep_alive
from datetime import datetime as dt
import time
import random

client = discord.Client()


@client.event
async def on_ready():
  print("I'm in")
  print(client.user)
  

@client.event
async def on_message(message):
  if message.author != client.user:
    if message.content.startswith(":H"):
      await message.channel.send('You Got me')
      message_content = message.content.split(' ')
      print(message_content[2])
      if message_content[1] == 'say':
        await sayFunction(message_content, message)
      elif message_content[1] == 'roll':
        await rollFunction(message_content, message)
      

        
    
    file = open('conversations.txt', 'a')
    print(message.author)
    print(message.channel.name)
    print(message.content)
    file.write('Author = '+ str(message.author))
    file.write('| Channel = '+ str(message.channel.name))
    file.write('| Said: ' + str(message.content))
    file.write('| At: ' + str(dt.now()) + '\n')
    file.close()
    

@client.event
async def sayFunction(message_content, message):
  
    message_content.remove(':H')
    message_content.remove('say')
    await message.channel.send(" ".join(message_content))

@client.event
async def rollFunction(message_content, message):
    a = message_content.split("d")
    b = []
    final = []
    a[0] = int(a[0])
    a[2] = int(a[2])
    for i in range(0, a[0]):
      for j in range(0, 4):
        b.append(random.randint(0, a[2]))
      final.append(b[random.randint(0, 5)])
      
    

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
    
    await message.channel.send("Final results for " + message_content[2] +": " + " ".join(final))



    

keep_alive()
token = os.environ.get('DISCORD_BOT_SECRET')
client.run(token)