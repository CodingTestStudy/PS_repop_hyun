//효율성 실패
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

int gem[100000+1];
int arr[100000+1];
map<string,int> m;
set<int> s;
bool comp( pair<int,int> t,pair<int,int> tt){
    if(t.second == tt.second)return t.first < tt.first;
    else return t.second <= tt.second;
    
    
    
}
bool check(int size){
    
    for(int i = 0 ; i < size ; i++){
        if(gem[i] == 0){
            return false;
        }
    }
    
    return true;
    
}
vector<int> solution(vector<string> gems) {
    
    vector<int> answer;
    vector<pair<int,int>> tmp;
    int i = 0;
    for(string e : gems){
    
        
        //없으면 생성
        if(m.find(e) == m.end()){
            int num = m.size();
            m.insert({e,num});
            arr[i] = num;
        }
        
        else {
            arr[i] = m[e];
        
        }
        i+=1;
    }
    
    memset(gem,0,sizeof(gem));
    int lo = 0;
    int hi = 0;
    s.insert(arr[lo]);
    
    while(lo < gems.size()){
    
     
        if (hi == gems.size()) {
            
            s.erase(s.find(arr[lo]));
			lo++;
            s.insert(arr[lo]);
			hi = lo;
			continue;

		}

        if(arr[hi] == arr[lo] && lo != hi){
          
            s.erase(s.find(arr[lo]));
            lo++;
            s.insert(arr[lo]);
            hi = lo;
            
        }
        
        
        
        if(hi - lo + 1 >= m.size()){
            if(m.size() == s.size()){
                tmp.push_back(make_pair(lo,hi-lo+1));//시작과 길이
                    
            }
            }   
  
        
        hi++;
        s.insert(arr[hi]);
        
    }
    
    sort(tmp.begin(),tmp.end(),comp);

    int ans = tmp[0].first;
    int ans2 =  tmp[0].first+ tmp[0].second - 1;
    answer.push_back(ans+1);
    answer.push_back(ans2+1);
 
    return answer;
}