import java.util.*;
import java.math.*;
class Solution {
    


    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        int size = citations.length;
        
        for(int i = 0 ; i < size; i++){
            if(citations[i] >= size-i){
                answer = size-i;
                return answer;
            }
            
        }
            
        return answer;
    }
}