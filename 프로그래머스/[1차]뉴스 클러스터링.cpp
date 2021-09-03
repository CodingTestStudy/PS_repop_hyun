
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define MAX(a,b) a>b ? a : b
#define MIN(a,b) a>b ? b : a
map<string,double> m1;
map<string,double> m2;

int solution(string str1, string str2) {
    int answer = 0;


    for(int i = 0 ; i < str1.length()-1;i++){
        if( ('a' <= str1[i]  && str1[i] <= 'z') || ('A' <= str1[i]  && str1[i] <= 'Z')){
             if( ('a' <= str1[i+1]  && str1[i+1] <= 'z')|| ('A' <= str1[i+1]  && str1[i+1] <= 'Z')){
                 string s="";
                 s.push_back(tolower(str1[i]));
                 s.push_back(tolower(str1[i+1]));

                 if(m1.find(s) != m1.end()){
                    m1[s] +=1;   
                 }
                 else m1.insert({s,1});

             }
        } 
    }

    for(int i = 0 ; i < str2.length()-1;i++){
        if( ('a' <= str2[i]  && str2[i] <= 'z') || ('A' <= str2[i]  && str2[i] <= 'Z')){
             if( ('a' <= str2[i+1]  && str2[i+1] <= 'z') || ('A' <= str2[i+1]  && str2[i+1] <= 'Z')){
                 string s="";
                 s.push_back(tolower(str2[i]));
                 s.push_back(tolower(str2[i+1]));
                 if(m2.find(s) != m2.end()){
                    m2[s] +=1;   
                 }
                 else m2.insert({s,1});

             }
        } 
    }

    //m1
    double cap = 0;
    double cup = 0;
    for(auto f : m1){

        if(m2.find(f.first) == m2.end()){

            cup += f.second;
        }
        else{
            cap += MIN(m2[f.first],m1[f.first]);
            cup += MAX(m2[f.first],m1[f.first]);
        }


    }

    for(auto f : m2){
         if(m1.find(f.first) == m1.end()){

            cup += f.second;
        }


    }
    if(cup ==0)answer = 65536;
    else answer = int(cap/cup * 65536);

    return answer;
}