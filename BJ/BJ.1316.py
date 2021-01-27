import sys

N = int(input())

inn = [sys.stdin.readline().rstrip() for i in range(N)]
ret = 0
for i in range(0,N):
    s = set()
    isOk = True
    ex = inn[i][0]
    for c in inn[i]:
        if c in s:
            if c == ex: #연속적인 것이면
                pass
            else :
                isOk = False
                break
        else :
            s.add(c)
            ex = c
    
    if isOk == True:
        ret+=1

    

print(ret)