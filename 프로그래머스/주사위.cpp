#include <string>
#include <vector>
#include <string.h>
#define MAXAN 10000
using namespace std;

string num;
bool check[10][4];

bool isOk(int a,int size){
    int cnt =0;
    
    for(int i = 0 ; i < 4 ; i++){
        if((a & (1 << i)) != 0){
            cnt +=1;
        }
    }
    
    if(cnt != size)return false;
    else return true;
}

int solution(vector<vector<int>> dice) {
    memset(check,false,sizeof(check));
    int answer = 0;
    
    for(int i = 0 ; i < dice.size() ; i++){
        for(int j = 0 ; j < dice[i].size() ; j++){
            check[dice[i][j]][i] = true;    
        }
    }
    
    
    for(int i = 1 ; i < MAXAN ; i++){
        bool flag = 0;
        int set=0x00;
        num = to_string(i);
        for(int j = 0 ; j < num.length(); j++){
            int n = num[j] - '0';
     
            for(int k = 0 ; k < dice.size() ; k++){
                if(check[n][k]){
                    if((set & (1 << k)) == 0){
                        set = (set | (1 <<k));
                        break;
                    }
                    
                }  
            }
          
            if(!isOk(set,j+1)){
            int set2=0x00;
            for(int l = 0 ; l < num.length(); l++){
                int n = num[l] - '0';

                for(int g = dice.size()-1 ; g >= 0; g--){
                    if(check[n][g]){
                        if((set2 & (1 << (g))) == 0){
                            set2 = (set2 | (1 <<(g)));
                            break;
                        }

                    }  
                }

            if(!isOk(set2,l+1)){
                answer = i;
                flag = 1;
                break;
                }
            }
            
            
            
            
            
         }
        
          
           
        }
        
        if(flag)break;
    }
    
    return answer;
}