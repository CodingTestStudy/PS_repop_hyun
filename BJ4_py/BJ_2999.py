
import sys
import math

msg = input()
N = len(msg)
R = 1 


for x in range(1,int(math.sqrt(N)+1)):
    if N % x == 0 : R = x

C = N//R


ans = ""

for i in range(0,R):
    ptr = i
    for j in range(0,C):
        ans += msg[ptr]
        ptr+= R

print(ans)