class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        if len(s) == 1:
            return s
        
        for i in range(0,len(s)):
            for j in range(len(s), i , -1):
                if len(ans) >= j - 1:break
                
                elif s[i:j] == s[i:j][::-1]:
                    ans = s[i:j]
                    break
        

                
        
        return ans