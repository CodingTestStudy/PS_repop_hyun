import functools
import sys
from functools import cmp_to_key

def comp(a, b):
    if a[0] == b[0]:
        return a[1] < b[1]
    else:
        return a[0] < b[0]



R,C = map(int,sys.stdin.readline().rstrip().split())
arr=[[0]*R]
cordi = list()
for i in range(R):
    tmp = sys.stdin.readline().rstrip()
    for x in tmp:
        if x == '.':
            arr[i].append('.')
        elif x == 'X':
            arr[i].append('X')

    


for i in arr:
    for j in range(C):
        if arr[i][j] == 'X':
            cordi.append(tuple(i,j))


cordi.sort(key= functools.cmp_to_key(comp))

print(cordi)