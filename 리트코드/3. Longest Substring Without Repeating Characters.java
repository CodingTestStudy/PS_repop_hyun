package 리트코드;

import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        HashSet<Character> set = new HashSet<Character>();
        int st = 0;
        int end = 0;
        int ans = 0;
        while(end < s.length() ){

            
            if(set.contains(s.charAt(end))){
                set.remove(s.charAt(st));
                st++;
               
                
            }else{
                
                set.add(s.charAt(end));
                end++;
                ans = Math.max(ans,set.size());
                
            }
        
        }

        
        return ans;
    }
}