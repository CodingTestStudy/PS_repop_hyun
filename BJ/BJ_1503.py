import sys
N,M = input().split()
N = int(N)
M = int(M)

if M != 0:
    S = set(map(int,sys.stdin.readline().split()))
    Nat = []
    for i in range(1,1002):
        if i not in S:
            Nat.append(i)

    ret = 987654321
    isEnd = False
    for i in range(0,len(Nat)):
        for j in range(0,len(Nat)):
            for k in range(0,len(Nat)):
                if N - Nat[i]*Nat[j]*Nat[k] < 0:
                    ret = min(ret, abs(N- Nat[i]*Nat[j]*Nat[k]))
                    isEnd = True
                    break
                ret = min(ret,abs(N -  Nat[i]*Nat[j]*Nat[k]))

            

    print(ret)

else:
    print(0)