import random

message_content = [':H', "roll", "1d6"]
a = message_content[2].split("d")
print (a)
b = []
final = []
a[0] = int(a[0])
a[1] = int(a[1])
for i in range(0, a[0]):
    for j in range(0, 5):
        b.append(random.randint(0, a[1]))
    print(b)
    final.append(b[random.randint(0, 4)])
    print (final)
print("Final results for " + message_content[2] +": " + " ".join(map(str, final)))