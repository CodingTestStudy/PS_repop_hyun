#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int arr[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};
int yy[4]= {-1,1,0,0};
int xx[4] = {0,0,-1,1};


int BFS(int st,int ed){
    bool discover[4][3];
    int ret[4][3];
    memset(discover,0,sizeof(discover));
    memset(ret,0,sizeof(ret));
    
    pair<int,int> s;
    pair<int,int> e;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(arr[i][j]== st){
                s = make_pair(i,j);
            }
            if(arr[i][j] == ed){
                e = make_pair(i,j);
            }
        }
    }
    

    
    queue<pair<int,int>> q;
    q.push(s);
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == e.first && x == e.second)break;
        
        for(int i = 0 ; i < 4 ; i++){
            int n_y = y + yy[i];
            int n_x = x + xx[i];
            if(0<= n_y && n_y <4 && 0<= n_x && n_x <4){
               if(!discover[n_y][n_x]){
                   
                   discover[n_y][n_x] = 1;
                   ret[n_y][n_x] = ret[y][x] + 1;
                   q.push({n_y,n_x});
                   
               }
            }
         
            
        }
        
        
    }
    
    
    return ret[e.first][e.second];
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 11;
    for(int i = 0 ; i < numbers.size() ; i++){
        
        int end = numbers[i];
        if(end == 1 || end == 4 || end == 7){
            left = end;
            answer += "L";
        }
        else if(end == 3 || end == 6 || end == 9){
                right = end;
                answer += "R";
        }
        else{
            int l = BFS(left,end);
            int r = BFS(right,end);
        
            if(l < r){
                left = end;
                answer += "L";
            }
            else if(l > r){
                right = end;
                answer += "R";
            }
            else if (l == r){
                if(hand == "right"){
                    right = end;
                    answer += "R";
                }
                else{
                    left = end;
                    answer += "L";
                }
            }
            
        }
        
        
        
    }
    return answer;
}