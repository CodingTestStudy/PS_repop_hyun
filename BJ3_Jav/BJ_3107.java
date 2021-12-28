
import java.io.*;
import java.util.*;
import java.lang.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static void main(String[] args) throws IOException{

     FastScanner fs = new FastScanner();
     String inn = fs.next();
    
     StringBuilder ans = new StringBuilder();


     String []tmp = inn.split(":");
     int lenOfTmp = 0;
     for(int i = 0 ; i < tmp.length ; i++){
        if(tmp[i].length() != 0)lenOfTmp++;
     }
   
     boolean flag = false;
     for(String e : tmp){
    
         if(e.length() != 0&&e.length() <= 4){
            
            StringBuilder t = new StringBuilder(e);
            
            for(int i = 0 ; i < 4-e.length(); i++){
                t.insert(0,"0");
            }
            ans.append(t);
            ans.append(":");
          
        }
   
        else if(flag == false&&e.length() == 0){
            flag = true;
            int remainZero = 8-lenOfTmp;

            for(int i = 0 ; i < remainZero ; i++){
                ans.append("0000:");
            }

        }

     }

    while(ans.length() < 39){
        ans.append("0000:");
        
    }


     String answer = ans.substring(0, ans.length()-1);
     System.out.println(answer);
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