
n = int(input())
arr = [0]*26
stack = []
oper = input()
for x in range(0,n):
    arr[x] = int(input())

oper = [arr[ord(x)-65] if x.isalpha() == True else x for x in oper]

for e in oper:
    if type(e) == int or type(e) == float:
        stack.append(e)
    elif type(e) == str:
        opTwo = float(stack.pop())
        opOne = float(stack.pop())
      
        if e == '*':
            stack.append(float(opOne*opTwo))
        elif e == '/':
            stack.append(float(opOne/opTwo))
        elif e == '+':
            stack.append(float(opOne + opTwo))
        elif e == '-':
            stack.append(float(opOne - opTwo))


print('{:.2f}'.format(float(stack.pop())))