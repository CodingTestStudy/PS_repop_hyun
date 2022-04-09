import sys

def er() :
    print(0)
    sys.exit(0)



def cal(t):
    tmpCal = 0
    if len(stack) == 0:
        er()

    while stack[-1] != t:
        if stack[-1] != t and type(stack[-1]) == str:
            er()
        
        tmpCal += int(stack.pop())
        if len(stack) == 0 : er()

    stack.pop()
    if tmpCal == 0 :
        tmpCal = 1
    return tmpCal


R = sys.stdin.readline().rstrip()
stack = []
ans = 0
for e in R:
    if e == '(' or e == '[':
        stack.append(e)
    
    elif e == ')':
        stack.append(2*cal('('))
    elif e == ']':
        stack.append(3*cal('['))



exc = ['(','[']
for _, e in enumerate(exc):
    if e in stack:
        er()
else :
    while len(stack) != 0:
        ans += stack.pop()
    
    print(ans)
