def solution(s):
    answer = len(s)
    
    for i in range(1, (len(s) // 2) + 1):
        prev = s[:i]
        comp = ""
        cnt = 1
        for j in range(i, len(s) + 1, i):
            if prev == s[j:j + i]:
                cnt += 1
            else :
                comp += str(cnt) + prev  if cnt > 1 else prev
                prev = s[j: j + i]
                cnt = 1
        
        
        comp += str(cnt) + prev if cnt > 1 else prev
        answer = min(answer,len(comp))
            
            
    return answer



print("시작")
s = input()

print(solution(s))