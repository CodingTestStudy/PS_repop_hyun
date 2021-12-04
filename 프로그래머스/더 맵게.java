import java.util.*;
class Solution {
    static PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        for(int s : scoville){
            pq.offer(s);
        }
        
        
        while(pq.size() !=1){
            int f = pq.poll();
            if(f >= K){
                return answer;
            }
            int s = pq.poll();
            int n = f + (s*2);
            pq.offer(n);
            
            answer++;
        }
        if(pq.poll() >= K)return answer;
        return -1;
    }
}