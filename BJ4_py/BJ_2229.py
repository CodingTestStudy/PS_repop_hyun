import sys

N = int(input())
dp = [0]*(N+1)
students = list(map(int,sys.stdin.readline().rstrip().split()))


for x in range(0,N):
    mmin = mmax = students[x]
    for y in range(x,-1,-1):
        mmin = min(mmin,students[y])
        mmax = max(mmax,students[y])
        dp[x+1] = max(dp[x+1],dp[y] + mmax - mmin)


print(dp[N])

