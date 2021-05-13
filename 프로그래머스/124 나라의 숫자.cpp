#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(int n) {
    string answer = "";
    string tmp ="";

    do{
        
        int r = n % 3;
        
        if(r == 1)tmp+= "1";
        if(r == 2)tmp+="2";
        if(r == 0){
            n -=1;
            tmp+="4";
        }
        
        
        n/=3;
        
    }while(n != 0);
    
    
    for(int i =tmp.length() - 1 ; i >=0 ; i--){
        if(tmp[i] == '1'){
            answer += "1";
        }
        
        else if(tmp[i] == '2'){
            answer += "2";
        }
        
        else if(tmp[i] == '4'){
             answer += "4";
            
        }
        
    }
    
    
    
    return answer;
}