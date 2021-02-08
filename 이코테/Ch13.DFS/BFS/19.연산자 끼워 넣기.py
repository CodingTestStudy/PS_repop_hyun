import sys


N = int(input())

num = list(map(int,input().split()))
oper = list(map(int,input().split()))


result = []
def DFS(n,ret) :
    if n == N - 1 :
        result.append(ret)
        return


    if oper[0] :
        oper[0]-=1
        nxt = ret + num[n+1]
        DFS(n+1,nxt)
        oper[0]+=1
    
    if oper[1] :
        oper[1]-=1
        nxt = ret - num[n+1]
        DFS(n+1,nxt)
        oper[1]+=1
    
    if oper[2] :
        oper[2]-=1
        nxt = int(ret * num[n+1])
        DFS(n+1,nxt)
        oper[2]+=1
    
    if oper[3] :
        oper[3]-=1
        if ret < 0:
            ret = -ret
            nxt = ret // num[n+1]
            nxt = -nxt
        else :
            nxt = ret // num[n+1]
            
        DFS(n+1,nxt)
        oper[3]+=1

    return





DFS(0,num[0])

result.sort()

print(result[-1])
print(result[0])
