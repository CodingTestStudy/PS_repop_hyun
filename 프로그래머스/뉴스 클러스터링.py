
import math 
def solution(str1, str2):
    
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()
    st1 = list()
    st2 = list()
    for i in range(0,len(str1)):
        if i == len(str1)-1: break
        if ('a' <=str1[i] and str1[i] <= 'z') and ('a' <=str1[i+1] and str2[i+1] <= 'z'):
            tmp = ""
            tmp += str1[i] + str1[i+1]
            st1.append(tmp)
    
    for i in range(0,len(str2)):
        if i == len(str2)-1: break
        if ('a' <=str2[i] and str2[i] <= 'z') and ('a' <=str2[i+1] and str2[i+1] <= 'z'):
            tmp = ""
            tmp += str2[i] + str2[i+1]
            st2.append(tmp)
    
        
    if len(st1) == 0 and len(st2) == 0:
        return 65536
    
    comb = set(st1) & set(st2)
    uni = set(st1) | set(st2)

    if len(comb) == 0 and len(uni) != 0:
        return 0
    minCount = list()
    maxCount = list()
    for x in uni:
        A = 0
        B = 0
        for a in st1:
            if x == a :
                A+=1
        
        for b in st2:
            if x == b:
                B+=1
        
        maxi = max(A,B)
        mini = min(A,B)
        if mini == 0 : mini = 1
        maxCount.append(maxi)
        minCount.append(mini)
    
    
    minSum = 0
    maxSum = 0

    print(minCount)
    print(maxCount)
    for m in minCount:
        minSum += m - 1
    
    for m in maxCount:
        maxSum += m - 1
        
    answer = math.floor(((len(comb) + minSum) / (len(uni) + maxSum)) * 65536)
     
    
    return answer


print(solution("aa", "aa"))