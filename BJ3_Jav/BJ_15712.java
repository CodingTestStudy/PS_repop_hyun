
import java.io.*;
import java.util.*;

public class test {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static long A,R,N,M;

    static long expo(long x, long y){
        long ret = 1L;
        while(y>0){
            if(y % 2 == 1){
                ret = (ret*x)%M;
            }
            x = (x*x)%M;
            y/=2;
        }
        return ret%M;
    }

    static long func(long n){

        if(n == 0)return 1;
        if(n == 1)return (1+R) % M;

        if(n % 2 == 1)return  (expo(R,n/2 + 1)+ 1)*func(n/2) % M;
        else return (expo(R,n)%M + func(n-1)%M)%M;
    }
    public static void main(String[] args) throws IOException{
        FastScanner fs = new FastScanner();
        A = fs.nextLong();
        R = fs.nextLong();
        N = fs.nextLong();
        M = fs.nextLong();
        
        long ret = (A*func(N-1)) % M;
        
        bw.write(Long.toString(ret));
        bw.flush();
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