import sys

str = sys.stdin.readline().rstrip()
ans = list()

for x in str:
    if x.isupper():
        ans.append(x)
    else : pass


for val in ans:
    print(val,end="")