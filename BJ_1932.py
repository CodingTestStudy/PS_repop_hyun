#이코테 376p 정수 삼각형 백준 문제

N = int(input())

dp = []

for i in range(1,N+1):
    inn = list(map(int,input().split()))
    dp.append(inn)

for i in range(N-1,0,-1):
    for j in range(0,i):
        dp[i-1][j] = max(dp[i][j],dp[i][j+1]) + dp[i-1][j]



print(dp[0][0])
