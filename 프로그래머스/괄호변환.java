import java.util.*;

class Solution {
    
    static String[] make_uv(String w){
    
        int l = 0;
        int r = 0;
        int mark = 0;
        for(int i = 0 ;i <  w.length() ; i++){
            if(w.charAt(i) == '(')l++;
            else if(w.charAt(i) == ')')r++;
            
            if(l == r){
                mark = i;
                break;
            }
            
        }   
        
        
        String[] ret = new String[]{w.substring(0,mark+1),w.substring(mark+1)};
        return ret;
    }
    
    
    //올바른 괄호 문자열 확인함수
    static boolean checkAllright(String s){
        
        Stack <Character> st = new Stack<>();
        
       
        for(int i = 0 ; i < s.length() ; i++){
            if(s.charAt(i) == '(') st.push(s.charAt(i));
            
            if(s.charAt(i) == ')'){
                
                if(st.empty()) return false;
                
                else{
                    st.pop();
                    
                }
            }
            
        }
        
        if(!st.empty())return false;
        else return true;
        
        
    }    
    
    static String reversing(String u){
        String ret = "";
        for(int i = 0 ; i < u.length() ; i++){
            if(u.charAt(i) == '('){
                ret +=')';
            }   
            else if(u.charAt(i)  == ')')ret += '(';
        }
        return ret;
    }
    
    static String doFourth(String u,String v){
        
        String ret = "(";
        String vRet = processing(v);
        ret += vRet + ")";
        u = u.substring(1,u.length()-1);
        u = reversing(u);
        ret += u;
        return ret;
        
    }
    
    static String processing(String w){
        if(w.equals(""))return "";
        else{
            String []UV = make_uv(w);
            String ret = ""; 
            if(checkAllright(UV[0])){ //u  올바른지
                ret +=processing(UV[1]);
                ret = UV[0] + ret;
                return ret;
            }
            
            else if(checkAllright(UV[0]) == false){
                
                ret = doFourth(UV[0],UV[1]);
                
                return ret;
                
            }
            
        }
        return "";
    }
    public String solution(String p) {
        String answer = "";
        
        answer = processing(p);
        
        
        return answer;
    }
}