package BJ3;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;



public class BJ_1152{
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
     
        String input = br.readLine().trim();
        if(input.equals("")){
                 
            bw.write(String.valueOf(0) + '\n');
        
            bw.flush(); 
            bw.close();
            return;
        }
        String [] word = input.split(" ");
      
      
       bw.write(String.valueOf(word.length) + '\n');
      

       bw.flush(); 
       bw.close();
      

       
    }


}




