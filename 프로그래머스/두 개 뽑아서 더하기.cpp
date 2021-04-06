#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    
    for(int i = 0 ; i < numbers.size(); i++){
        for(int j = i + 1  ; j < numbers.size() ; j++){
            int ret = numbers[i] + numbers[j];
            answer.push_back(ret);
        }
    }
    
    
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    
    return answer;
}