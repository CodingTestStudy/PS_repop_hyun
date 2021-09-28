class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip()
        isMinus = 0
        isPlus = 0
        ans = ""
        if s == "":
            return 0
        
        if s[0] == "+":
            isPlus = 1
            s = s[1:]
        elif s[0] == '-':
            isMinus = 1
            s = s[1:]
    
        for x in s:
            if not x.isdigit():
                break
            else:
                ans += x
        
        
        if ans == "":
            return 0
        
        
        if isMinus:
            ans = int(ans)
            ans = -ans
            if ans < -(pow(2,31)):
                return -pow(2,31)
            return ans
        else:
            ans = int(ans)
            if ans > pow(2,31) - 1:
                return pow(2,31) - 1
            return ans
                