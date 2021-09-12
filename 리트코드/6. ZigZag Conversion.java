package 리트코드;

import java.util.*;
import java.io.*;
class Solution {
    static int max;
    public String print(char[][] arr,int r){
        String ans = "";
        for(int i = 0 ; i < r ; i++){
            
            for(int j = 0 ; j < max ;j++){
                if(arr[i][j] == ' ')continue;
                else{
                    ans += arr[i][j];
                }
                
            }
            
        }
    
        return ans;
    }
    
    
    public String convert(String s, int numRows) {
      char[][] arr = new char[numRows][2001];
      max = s.length();
      for(char[] a : arr){
          Arrays.fill(a,' ');
      }
       
      int idx = 0;
      int c = 0;
      while(idx < s.length()){
        for(int i = 0 ; i < numRows ; i++){
            if(idx >= s.length())break;
            arr[i][c] = s.charAt(idx++);
        }
        if(idx >= s.length())break;
        
        
        for(int i = numRows - 2 ; i>=1 ; i--){
            if(idx >= s.length())break;
            arr[i][++c] = s.charAt(idx++);  
        }
        c+=1;
      }
  
    
      return print(arr,numRows);
        
    }
}