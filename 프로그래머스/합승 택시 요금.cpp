#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


const int INF = 0x3f3f3f3f;

int adj[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    memset(adj,INF,sizeof(adj));
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j <=n ; j++){
            if(i == j)
                adj[i][j] = 0;
        }
    }
    for(vector<int> ad : fares){
        int from = ad[0];
        int to = ad[1];
        int cost = ad[2];
        adj[from][to] = min(adj[from][to],cost);
        adj[to][from] = min(adj[to][from],cost);
    }    
    for(int i = 1 ; i <= n ; i++){
        
        for(int j = 1 ; j <= n ; j++){
            
            if(adj[j][i] == INF)continue;
            
            for(int k = 1 ; k <= n ; k++){
                adj[j][k] = min(adj[j][k],adj[j][i] + adj[i][k]);           
             }
                
            }
        }
        
    
        
    answer = adj[s][a] + adj[s][b];
    for(int m = 1 ; m<= n ; m++){
        
        if(adj[s][m] != INF){
        int tmp = adj[s][m] + adj[m][a] + adj[m][b];
        answer = min(answer,tmp);
        }
        
    }
    
    return answer;
}