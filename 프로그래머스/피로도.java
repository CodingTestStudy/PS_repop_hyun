import java.util.*;
import java.math.*;

class Solution {
    static int dSize;
    static int ans;
    static int K;
    static boolean visited[];
    static List<Integer> ret = new ArrayList<Integer>();
    static void dive(int[][] dungeons){
        
        if(ret.size() == dSize){

            int k = K;
            int tempAns = 0;
            for(int i = 0 ; i < ret.size() ; i++){
                
                if(k>= dungeons[ret.get(i)][0]){
                    k-=dungeons[ret.get(i)][1];
                    tempAns++;
                }
                else{
                    break;
                }
                
            }
            
            ans = Math.max(ans,tempAns);
            return;
            
        }
        
        
        for(int i = 0 ; i < dSize ; i++){
            
            if(visited[i] == false){
                visited[i] = true;
                ret.add(i);
                dive(dungeons);
                ret.remove(ret.size()-1);
                visited[i]= false;
            }
            
        }
      
        
        
        
    }
    
    public int solution(int k, int[][] dungeons) {
       
        ans = -1;
        dSize = dungeons.length;
        visited = new boolean[dungeons.length+1];
        for(int i = 0 ; i < visited.length ; i++){
            visited[i] = false;
        }
        K = k;
        dive(dungeons);
       
        
        return ans;
    }
}