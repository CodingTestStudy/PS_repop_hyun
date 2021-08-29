#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define MAXN 502
typedef pair<double,int> P;
double cnt[MAXN+1];
vector<P> v;
bool comp(P &a , P &b){
 
    if(a.first == b.first)return a.second < b.second;
    else return a.first > b.first;

}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    memset(cnt,0,sizeof(cnt));
    
    for(int i = 0 ; i < stages.size() ; i++){
        
        cnt[stages[i]] +=1;
        
    }
    
    
    double d = double(stages.size());
    for(int i = 1 ; i <= N ;i++){
        if(d == 0)v.push_back({0,i});
        else{
            v.push_back({cnt[i]/d,i});
            d-=cnt[i];
        }
    }
    
    sort(v.begin(),v.end() ,comp);
    
    for(P s : v){
        answer.push_back(s.second);
    }
    
    return answer;
}