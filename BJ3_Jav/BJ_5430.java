
import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int dir;
    static Deque<String> dq;

    static void discard(){
        //순방향
        if(dir == 0){
            dq.removeFirst();
        }
        else if(dir == 1){ //역방향
            dq.removeLast();
        }
        

    }
    static void printing() throws IOException{
        
        StringBuilder ret = new StringBuilder();
        ret.append("[");
        if(dir == 0){
           while(dq.isEmpty()==false){
                ret.append(dq.pollFirst());
                if(dq.isEmpty() == false)ret.append(",");
            }
            ret.append("]");
        }
        else if(dir == 1){
            while(dq.isEmpty()==false){
                ret.append(dq.pollLast());
                if(dq.isEmpty() == false)ret.append(",");
            }
            ret.append("]");

        }

        bw.write(ret.toString() +"\n");

    }
    public static void main(String[] args) throws IOException{
        
        FastScanner fs = new FastScanner();
        int t = fs.nextInt();
        while(t-- != 0){
            Boolean flag = false;
            dir = 0; //순방향
            dq = new ArrayDeque<>();
            String p = fs.next();
            int len = fs.nextInt();
            String arr = fs.next();
          

            arr = arr.substring(1,arr.length()-1 );
            String[] num = arr.split(",");
            
            for(int i = 0 ; i < len ; i ++){
                dq.add(num[i]);
            }
    

            for(int i = 0 ; i < p.length() ; i++){
                if(p.charAt(i) == 'R'){
                    dir = (dir ^ 1); //방향 바뀜
                }
                else if( p.charAt(i)=='D'){

                    if(dq.size() == 0){
                        flag = true;
                        break;
                    }
                    else discard();
                }
            }
            
            if(flag == true)bw.write("error\n");

            else printing();

            

        }

        bw.flush();
        bw.close();
    	
    }
    
    //입력 함수
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