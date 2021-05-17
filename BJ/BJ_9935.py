import sys


input = list(sys.stdin.readline().rstrip())
explo = list(sys.stdin.readline().rstrip())
stack = list()

last = explo[-1]
for x in input:
    stack.append(x)
    if x == last and ''.join(stack[-len(explo):]) == ''.join(explo) :
        del stack[-len(explo):]

ans = ''.join(stack)

if not ans :
    print('FRULA')

else:
    print(ans)

     