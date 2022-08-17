import sys


N,K = map(int,sys.stdin.readline().rstrip().split())
students = list(map(int,sys.stdin.readline().rstrip().split()))
diff = list()

for i in range(N-1):
    diff.append(students[i+1] - students[i])


diff.sort()

print(sum(diff[:N-K]))

