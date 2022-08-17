#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<string> uId;
set<char> s;
bool isSame(const string& target, const string& origin){
    if(target.length() != origin.length())return false;
    
    for(int i = 0  ; i < origin.length() ; i++){
        if(origin[i] == '*')continue;
        
        if(target[i] != origin[i])return false;
    }
    
    return true;
    
}
bool isAvaliable(vector<string> &bannedAdv,vector<string> &banned_id){
    
    for(int i = 0 ; i < bannedAdv.size() ; i++){
       if(isSame(bannedAdv[i],banned_id[i]) == false)return false;
        
    }
    
    //중복 체크용
    char c = 0;
    for(string& s : bannedAdv){
        for(int i = 0 ; i < uId.size();i++){
        
            if(s == uId[i]){
                c |= (1<<i);
              
            }
                
        }
    }
    if(s.find(c) != s.end())return false;
    else{
        s.insert(c);
        return true;
    }
    
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    sort(user_id.begin(),user_id.end());
    uId = user_id;
    do{
        vector<string> banned;
        
        for(int i = 0 ;i < banned_id.size() ;i++){
            banned.push_back(user_id[i]);
        }
        
        if(isAvaliable(banned,banned_id))
            answer+=1;
        
        reverse(user_id.begin() + banned_id.size(), user_id.end());
        
    }while(next_permutation(user_id.begin(),user_id.end()));
    
    
    
    
    return answer;
}