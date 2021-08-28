//효율성 실패
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
stack<int> st;
vector<int> v;
string solution(int n, int k, vector<string> cmd) {
 
    string answer = "";
    int lastIdx = n-1;
    int cur = k; //iter
  
    for(int i = 0 ; i < n ; i ++){
        v.push_back(i);
    }
    
    for(int i = 0 ; i < cmd.size() ; i++){
        
        char c = cmd[i][0];
        
        if(c == 'U'){
            
            int x = stoi(cmd[i].substr(2));
            cur-=x;
 
      
            
        }
        else if(c == 'D'){
            int x = stoi(cmd[i].substr(2));
            cur +=x;
         
        }
        else if(c == 'C'){
            
            if(v[cur] == lastIdx){
                st.push(v[cur]);
                v.erase(v.begin()+cur);
                cur--;
                lastIdx = v[cur]; //마지막 idx갱신
        
            }
            else{
                 st.push(v[cur]);
                 v.erase(v.begin()+cur);

            }
            
        }
        
        else if(c == 'Z'){
            
            int recover = st.top();
            st.pop();
            if(lastIdx < recover){
                lastIdx = recover;
                v.push_back(recover);
            
            }
            else{
                if(recover < v[cur]){
                    cur++;
                }
                vector<int>::iterator it = lower_bound(v.begin(),v.end(),recover);
                v.insert(it,recover);
               
            }
           
            
        }
        
    }
    
    
    for(int i = 0 ; i < n ; i++){
        
     
        if(find(v.begin(),v.end(),i)!= v.end())answer.push_back('O');
        else answer.push_back('X');

        
    }
    return answer;
    
    
}