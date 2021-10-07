class Solution:
    def reverse(self, x: int) -> int:
        minus = 0
        if x<0:
            minus =1
            x = -x
        
        st = str(x)
        
        st = st[::-1]
        
        ans = int(st)
        if minus == 1:
            ans = -ans
        
        if ans < -2**31 or 2**31 - 1 < ans:
            return 0
        
        return ans