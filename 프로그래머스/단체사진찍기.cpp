#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int condition[10][10];
char item[8] = {'A','C','F','J','M','N','R','T'};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    memset(condition,0,sizeof(condition));
    int answer = 0;
   
    sort(item,item+8);
    
    do{
        bool flag = true;
        for(int i = 0 ; i < data.size(); i++){
            if(flag == false)break;
            char n1 = data[i][0];
            char n2 = data[i][2];
            int dist = data[i][4] - '0';
            dist+=1;
            int n1_idx = -1;
            int n2_idx = -1;
            
            for(int j = 0 ; j < 8 ; j++){
                
                if(item[j] == n1)n1_idx = j;
                if(item[j] == n2)n2_idx = j;
                
                if(n1_idx != -1 && n2_idx !=-1)break;
            }
            
            if(data[i][3] == '='){
                if(abs(n1_idx - n2_idx) == dist){
                    flag = true;
                }
                else flag = false;
               
            }
            else if(data[i][3] == '>'){
                
                if(abs(n1_idx - n2_idx) > dist){
                    flag = true;
                }
                else flag = false;
            }
            else if(data[i][3] == '<'){
                  if(abs(n1_idx - n2_idx) < dist){
                    flag = true;
                }
                else flag = false;
          
            }
            
      
              
        }
        
        if(flag)answer++;
        
    }while(next_permutation(item,item+8));
  
    
    return answer;
}