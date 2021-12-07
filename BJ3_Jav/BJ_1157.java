import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] arr = new int[27];
    public static void main(String[] args) throws IOException{

     FastScanner fs = new FastScanner();
     
     String input = fs.next();
     input = input.toUpperCase();
     
     for(int i = 0 ; i < input.length() ; i++){
         
        arr[input.charAt(i) - 65] +=1;

    }

    int maxCnt=0;
    for(int i = 0 ; i < arr.length ; i++){
         
       if(maxCnt <= arr[i]){
           maxCnt = arr[i];
       }

    }
    boolean flag = false;
    int ans = 0;
    for(int i = 0 ; i < arr.length ; i++){
        
        if(maxCnt == arr[i] && flag ==false){
        flag = true;
        ans = i;
        }
        else if(maxCnt == arr[i] && flag ==true){
            bw.write("?\n");
            bw.flush();
            return;
        }

    }
    
    bw.write((char)(ans+65));
    bw.flush();
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