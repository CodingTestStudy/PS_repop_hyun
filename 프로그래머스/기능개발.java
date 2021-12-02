import java.util.*;

class Solution {
    static final int complete = 100;
    static ArrayList<Integer> remainArr = new ArrayList<Integer>();
    static Stack<Integer> s = new Stack<Integer>();
    static int idxCnt;
    
    public void insert(int [] arr,int data){
        arr[idxCnt++]=data;
    }
    
    public int[] solution(int[] progresses, int[] speeds) {
        
        for(int i = 0 ; i < progresses.length ; i++){
            
            int remainder = complete - progresses[i];
            int date = remainder / speeds[i];
            
            if(remainder%speeds[i] != 0)date+=1;
            
            remainArr.add(date);
        }
        
        
        for(int i =  remainArr.size() - 1 ; i >=0 ; i--){
            s.push(remainArr.get(i));
        }
     
    
        ArrayList<Integer> answer = new ArrayList<>();
        
        while(!s.empty()){
            
            
            int t = s.peek();
            s.pop();
        
            int d = 1;
            if(s.empty()){
                answer.add(d);
                break;
            }
            while(!s.empty()&&t >= s.peek()){
                s.pop();
                d+=1;
            }
            
            answer.add(d);
            
        }
        
        int[] ret = new int[answer.size()];
        for (int i=0; i < ret.length; i++)
        {
            ret[i] = answer.get(i);
        }
        return ret;
  
    }
}