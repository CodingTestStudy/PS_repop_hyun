package BJ3_Jav;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        
        int score = Integer.parseInt(st.nextToken());
        if(score >= 90){
            bw.write("A\n");

        }else if( 80 <= score &&score < 90 ){
            bw.write("B\n");
        }else if(70<= score && score < 80){
            bw.write("C\n");
        }else if(60<= score && score < 70){
            bw.write("D\n");
        }else{
            bw.write("F\n");
        }
        
        bw.flush();bw.close();
        br.close();
        
        
        StringBuilder ans = new StringBuilder();
        String s = "hh";
        s.charAt(0);



    }
}

        // String str = "%!@#12aAff";
        // String match = "[^0-9a-zA-Z\\s]";
        // str =str.replaceAll(match, "");
        // System.out.println(str);
