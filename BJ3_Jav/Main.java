package BJ3_Jav;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    static boolean arr[] = new boolean[1000002];
    
    public static void main(String[] args) throws IOException{
        Arrays.fill(arr,false);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        
        long MIN = Long.parseLong(st.nextToken());
        long MAX = Long.parseLong(st.nextToken());
        
        for(long i = 2 ; i * i <=MAX;i++){

            long start = MIN / (i*i);
            if((start*i*i) != MIN)start+=1;
            for(long j = start ; (i*i*j)<= MAX ; j++){
                int idx = (int)((i*i*j)-MIN);
                arr[idx] = true;
            }

        }
        
        int ret = 0;
        for(int i = 0 ; i < MAX - MIN + 1 ; i++){
            if(!arr[i])ret++;
        }
        
        bw.write(ret+"\n");
    
    
        bw.flush();bw.close();
        br.close();
        



    }
}

        // String str = "%!@#12aAff";
        // String match = "[^0-9a-zA-Z\\s]";
        // str =str.replaceAll(match, "");
        // System.out.println(str);
