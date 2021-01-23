
import sys
inn = list(map(int,sys.stdin.readline().rstrip().split()))

inn[0] -= 1
if inn[0] < 0 :
    inn[0] = 23

inn[1] += 60 
inn[1] -= 45

if inn[1] >= 60 :
    inn[1] -= 60
    inn[0] += 1
    if inn[0] == 24:
        inn[0] = 0


print(inn[0], end=" ")
print(inn[1])

