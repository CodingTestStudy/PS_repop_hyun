#백준 1026 보물


N = int(input())

A = list(map(int,input().split(' ')))
B = list(map(int,input().split(' ')))

A.sort()
B.sort(reverse=True)

ret = 0
for i in range(0,len(A)):
    ret +=A[i]*B[i]

print(ret)
