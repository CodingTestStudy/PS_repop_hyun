#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int xx[4] = {1, 0, 0, -1};
int yy[4] = {0, 1 ,-1, 0};
int MAX;
const int INF =  0x3f3f3f3f;
int minCost = INF;
bool visited[26][26];
vector<vector<int>> arr;

int cost[26][26];
void DFS(int y,int x, int st,int cor, pair<int,int> dir){
    int cal = (st * 100) + (cor * 500);
    //도착
    if(y == MAX-1 && x == MAX - 1){
        minCost = min(minCost,cal);
        return;
    }
    
    
    visited[y][x] = true;
    
     if(cost[y][x] != INF){
        if(cal > cost[y][x]){
         visited[y][x] = false;
         return;        
        }
        else{
            cost[y][x] = cal;
        }
         
    }
    
    else if(cost[y][x] == INF)cost[y][x] = cal;
 
    for(int i = 0 ; i < 4 ; i++){
        int n_y = y + yy[i];
        int n_x = x + xx[i];
        pair<int,int> p = {yy[i],xx[i]};
        if(0<= n_y && n_y < MAX && 0<=n_x && n_x < MAX){
            if(!visited[n_y][n_x] && arr[n_y][n_x] == 0){
                if(p != dir){
                    
                    DFS(n_y,n_x,st+1,cor+1,p);
        

                }
                else if(p == dir){
                    DFS(n_y,n_x,st+1,cor,p);

                }
            }

        }
    
   
    }
    visited[y][x] = false;
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    memset(visited,false,sizeof(visited));
    memset(cost,INF,sizeof(cost));
    
    MAX = board[0].size();
    
    arr = board;
    
    visited[0][0]= true;
    for(int i = 0 ; i < 4 ; i++){
        int n_y = 0 + yy[i];
        int n_x = 0 + xx[i];
        pair<int,int> p = {yy[i],xx[i]};
        if(0<= n_y && n_y < MAX && 0<=n_x && n_x < MAX){
            if(!visited[n_y][n_x] && arr[n_y][n_x] == 0){
               DFS(n_y,n_x,1,0,p);
            }

        }
    }


    answer = minCost;
    
    return answer;
}