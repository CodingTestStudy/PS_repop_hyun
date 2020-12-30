inp = str(input())

lenght = len(inp)
sum = 0
sum2 = 0
for i in range(lenght):
    sum += int(inp[i])
    if i == (lenght//2)-1 :break
 

for i in range((lenght//2),lenght):
    sum2 += int(inp[i])


if sum == sum2:
    print("LUCKY")

else : print("READY")
