import discord
import os
from keep_alive import keep_alive
from datetime import datetime as dt
import time

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
      if message_content[1] == 'say':
        await sayFunction(message_content, message)
      

        
    
    file = open('conversations.txt', 'a')
    print(message.author)
    print(message.channel.name)
    print(message.content)
    file.write('Author = '+ str(message.author))
    file.write('| Channel = '+ str(message.channel.name))
    file.write('| Said: ' + str(message.content))
    file.write('| At: ' + str(dt.now()) + '\n')
    file.close()
    #await outFunction(message)
    #print("hi")
    

@client.event
async def sayFunction(message_content, message):
  
    message_content.remove(':H')
    message_content.remove('say')
    await message.channel.send(" ".join(message_content))

keep_alive()
token = os.environ.get('DISCORD_BOT_SECRET')
client.run(token)