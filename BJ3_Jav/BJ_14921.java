
import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N;
    static int[] arr;
    public static void main(String[] args) throws IOException{

     FastScanner fs = new FastScanner();

     
     N = fs.nextInt();
     arr = fs.readArray(N);
     
     int lo = 0;
     int hi = N-1;
     int ans = Integer.MAX_VALUE;

     while(lo < hi){
        
        int mid=arr[lo] + arr[hi];
        if(mid < 0){
            lo++;
        }
        else if(mid > 0){
            hi--;
        }
        
        else if(mid == 0){
            ans = 0;
            break;
        }
        
        if(Math.abs(mid) < Math.abs(ans)){
            ans = mid;
        }
        
    }

    System.out.println(ans);

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