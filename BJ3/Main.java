package BJ3;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    boolean[] visited = new boolean[5000];


    public static void main(String[] args) throws IOException{
        
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = "%!@#12aAff";
        String match = "[^0-9a-zA-Z\\s]";
        str =str.replaceAll(match, "");
        System.out.println(str);
    }
}
