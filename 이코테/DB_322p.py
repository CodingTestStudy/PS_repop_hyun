#문자열 재정렬

inp = list(map(str,input()))

num = []
ans = []
for i in inp:
    if ord(i) < 65 or ord(i) > 90:
          num.append(int(i))
    else :
        ans.append(i)

ans.sort()
for i in ans :
    print(i, end='')

print(sum(num))
