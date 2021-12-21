import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N,M,K;
    static List<Integer> adj[];
	// 진입차수를 세어주기 위한용도
    static int isExist[] = new int[100000 + 5];
    static int buildCount[] = new int[100000 + 5];
    static boolean construct(int cur){
		// 진입차수가 양수이면 지을수 없는 상태이므로 false
        if (isExist[cur] >0){
            return false;
        }
		// 지어진 이력이 있으면, 건물수를 늘리고 true
        if(buildCount[cur]>0){
            buildCount[cur]++;
            return true;
        }
		// 처음 짓는거라면, 자식들의 진입차수를 줄여주도록 해줘야한다.
        buildCount[cur]++;
        for(Integer e: adj[cur]){
            isExist[e]--;
                
        }
        return true;
        
    }
    static boolean destroy(int cur){
		// 이미 건물이 지어져 있다면,
        if(buildCount[cur]>0){
			// 건물 수를 줄이고
            buildCount[cur]--;
			//만약 건물이 전부 사라지면, 자식들의 진입차수를 늘려준다.
            if(buildCount[cur] == 0){
                for(Integer e: adj[cur]){
                    isExist[e]++;
                
                }
            }
            return true;
        }
        return false;
    }
    public static void main(String[] args) throws IOException{
    
       
     FastScanner fs = new FastScanner();
     N = fs.nextInt();M = fs.nextInt(); K = fs.nextInt();
     adj = new List[N+1];
     for(int i = 0 ; i<= N; i++){
        adj[i] = new ArrayList<>();
     }
     for(int i = 0 ; i < M ; i++){
         int a = fs.nextInt();
         int b = fs.nextInt();
		// 부모 -> 자식
         adj[a].add(b);
		// 자식의 진입차수를 늘려준다.
         isExist[b]++;
        
     }
     boolean flag = false;
     for(int i = 0 ; i < K ; i++){
         int a = fs.nextInt();
         int b = fs.nextInt();
         boolean ret = true;
         if(a == 2){ //건설
            ret =destroy(b);
         }
         else if(a==1){ //파괴
            ret = construct(b);
            
         }
         if(ret == false){
            flag = true;
        }
     }
     if(flag == true){
        bw.write("Lier!\n");
        bw.flush();
     
     }
     else{
         bw.write("King-God-Emperor\n");
         bw.flush();
        }
    bw.close();
    }
    
    
    static class FastScanner{
    	 
    	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         StringTokenizer st = new StringTokenizer("");
         String next() {
        	 while(!st.hasMoreTokens()) {
        		 try {
        			 st=new StringTokenizer(br.readLine());
        			 
        		 }catch(IOException e) {
        			 e.printStackTrace();
        		 }
        		
        	 }
        	 return st.nextToken();
         }
        int nextInt() {
        	return Integer.parseInt(next());
        	
        }
        
    	long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
        
        int[] readArray(int n) throws IOException{
            int a[] = new int[n];
            for(int i=0;i<n;i++) a[i]=nextInt();
            return a;
        }
        int[] readArrayFromOneString(int m) throws IOException{
            int a[] = new int[m];
            char[] charr = next().toCharArray();
            for(int i=0;i<m;i++) a[i] = Character.getNumericValue(charr[i]);
            return a;
        }
		
		
    	
    }
    
    
}



