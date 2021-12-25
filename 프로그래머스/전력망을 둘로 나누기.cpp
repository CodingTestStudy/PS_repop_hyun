#include <string>
#include <vector>
#include <string.h>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

using P = pair<int,int>;

int ans = 0x3f3f3f3f;
P cutting;
bool visited[100+5];
int N;
vector<int>adj[100+5];
int dfs(int cur){
    
    visited[cur]= true;
    int ret = 1;
    for(int i = 0 ; i <adj[cur].size() ;i++){
        int next = adj[cur][i];
        
    if((cur == cutting.first && next == cutting.second) || 
       (next == cutting.first && cur == cutting.second))continue;
        
        if(!visited[next]){
            
            ret += dfs(next);
            
        }
        
    }
    return ret;
    
}

void counting(){
    
    int first = -1;
    int second = -1;
    for(int i = 1 ;i<= N ; i++){
        if(!visited[i] && first == -1){
            first = dfs(i);
        }
        
        else if(!visited[i] && first != -1){
            
            second =dfs(i);
        }
    }
    

    ans = min(ans,abs(first-second));
}

int solution(int n, vector<vector<int>> wires) {

    N = n;
    
    for(int i = 0 ; i < wires.size() ; i++){
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    
    
    for(int i = 0 ; i < wires.size() ; i++){
        memset(visited,false,sizeof(visited));
        cutting = make_pair(wires[i][0],wires[i][1]);
        counting();
        
    }
    
    return ans;
}