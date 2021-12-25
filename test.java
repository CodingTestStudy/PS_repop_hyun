
import java.io.*;
import java.util.*;

public class test {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


    //퀵소트 해보기
    static void sorting(int[] arr){

    }

    public static void main(String[] args) throws IOException{

     FastScanner fs = new FastScanner();
    	
     int arr[] = {9,11,105,1,88,14858,6,18,90};
    
        sorting(arr);

    	
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