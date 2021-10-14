

class Solution
{
    public int solution(int n, int a, int b)
    {

        int k = 0;
        while(n !=1){
            k+=1;
            n /= 2;
            
        }
         int num1 = (a-1)/2;
         int num2 = (b-1)/2;
        int cnt = 1;
        boolean flag = false;
        while(cnt <= k){
             if(num1 == num2){
                 flag = true;
                 break;
             }
            else{
            num1 = num1/2;
            num2 = num2/2;
            cnt+=1;
            }
        
        }
        
        if(flag)return cnt;
        
        return k;
   
    }
}