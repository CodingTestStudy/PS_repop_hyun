import sys

N = int(input())
max_val = 0
T = []
dp = [0] * (N+1)
for i in range(1,N+1):
    inn= tuple(map(int,sys.stdin.readline().rstrip().split()))
    T.append(inn)

for i in range(N - 1 ,-1,-1 ):
    t = T[i][0] + i
    if t <= N:
        dp[i] = max(T[i][1]+ dp[t],max_val)
        max_val = dp[i]

    else :
        dp[i] = max_val


print(max_val)