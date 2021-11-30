class Solution {
    static boolean[] check = new boolean[46];
    static int matchCnt = 0;
    static int lower = 0;
    static int higher = 0;
    static int zeroCnt = 0;
    public int[] solution(int[] lottos, int[] win_nums) {
    
        
        for(int i = 1 ; i <=45 ; i++ ){
            check[i] = false;
        }
        
        for(int i = 0 ; i < win_nums.length ; i++){
            check[win_nums[i]] = true;
        }
        
        for(int i = 0 ; i < lottos.length ; i++){
            if(check[lottos[i]])matchCnt+=1;
            if(lottos[i] == 0)zeroCnt +=1;
        }
        
        lower = 7 - matchCnt;
        if(lower == 7) lower = 6;
        
        higher = 7 - (matchCnt + zeroCnt);
        if( higher == 7)  higher  = 6;
        int[] answer = {higher,lower};
        return answer;
    }
}