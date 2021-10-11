import java.util.*;


class Solution {
    int yy[] = {-1,1,0,0};
    int xx[] = {0,0,-1,1};
    int n;
    int m;
    boolean visited[][] = new boolean[101][101];
    int cnt[][] = new int[101][101];
        class Pair{
        int x,y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        int first(){
            return this.x;
        }
        int second(){
            return this.y;
        }
        
        
    }
    public int solution(int[][] maps) {
        n = maps.length;
        m = maps[0].length;
        
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(0,0));
        
        for(boolean r[] : visited){
             Arrays.fill(r,false);
        }
        for(int r[] : cnt){
             Arrays.fill(r,0);
        }
        

        
        while(q.size() !=0){
            
            Pair cur = q.poll();
            
            for(int i = 0 ; i < 4 ; i++){
            
                int n_y = cur.first()+yy[i];
                int n_x = cur.second()+xx[i];
              
                if(0<= n_y && n_y < n&& 0<=n_x && n_x < m){
                    if(!visited[n_y][n_x]  && maps[n_y][n_x] == 1){
                        visited[n_y][n_x] = true;
                        cnt[n_y][n_x] = cnt[cur.first()][cur.second()] + 1;
                        q.add(new Pair(n_y,n_x));
                        
                    }
                }
            
            }
            
            
        }
        
        
    
        if(cnt[n-1][m-1] ==0)return -1;
        return cnt[n-1][m-1]+1;
    }


    
    
}