import sys



N = int(input())

board = []
for _ in range(N):
    t = tuple(map(int,sys.stdin.readline().rstrip().split()))
    board.append(t)    
    

board.sort(key=lambda x: x[2],reverse=True)

dup = dict()
cnt = 0
ans = list()
for x in board:
    if x[0] in dup:
        if dup[x[0]] >= 2:
            pass
        else:
            dup[x[0]] +=1
            cnt+=1
            ans.append(x)
    
    else:
        dup[x[0]] = 1
        cnt+=1
        ans.append(x)

    if cnt == 3 : break


for x in ans:
    print("{} {}".format(x[0],x[1]))