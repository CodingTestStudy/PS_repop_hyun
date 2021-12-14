import java.util.*;
import java.lang.*;
class Solution {
    static HashMap<String,Integer> map;
    static int maxNum = 0;
    public String[] solution(String[] orders, int[] course) {
        List<String> ret = new ArrayList<String>();
        for(int i  = 0 ; i < course.length ; i++){
            maxNum = 0;
            map = new HashMap<String,Integer>();
            for(int j = 0 ; j < orders.length ; j++){
                dfs(0,course[i],orders[j],"",0);
            }
            
            
            for(String e : map.keySet()){
                if(map.get(e) == maxNum && maxNum > 1){
                    ret.add(e);
                }
            }
        }
        Collections.sort(ret);
        String[] answer = new String[ret.size()];
        int k = 0;
        for(String e : ret){
        
            answer[k++] = e;
            
        }
        return answer;
    }
    public static void dfs(int cnt, int size , String order,String cur,int idx){
        if(cnt == size){
            
            char []t = cur.toCharArray();
            Arrays.sort(t);
            
            StringBuilder t2 = new StringBuilder();
            for(char e : t)t2.append(e);
            
            String tt = t2.toString();
            map.put(tt,map.getOrDefault(tt,0) + 1);
            Integer m = map.get(tt);
            maxNum = Math.max(maxNum,m);
            return;
            
        }
        else{
            
            for(int i = idx ; i < order.length() ; i++){
                char t = order.charAt(i);
                dfs(cnt + 1, size, order,cur+t,i+1);
                
            }
            
            
        }
        
        
    }
    
}