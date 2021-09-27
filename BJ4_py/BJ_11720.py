import sys

n = sys.stdin.readline().rstrip()
str = sys.stdin.readline().rstrip()
ans = 0
for i in str:
    ans += int(i)


print(ans)