//백준 10799 쇠막대기
//스택응용.. 
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	stack<char> s;
	string input;
	cin >> input;
	int ret = 0;
	for (int i = 0; i < input.length(); i++) {

		if (input[i] == '(') {
			s.push('(');
		}
		else if (input[i] == ')') {
			s.pop();//'(' 스택에서 제거
			if (input[i - 1] == ')') { //파이프 끝인 경우
				ret += 1;
			}
			else { //레이저인 경우
				ret += s.size();
			}
		}
	}
	
	cout << ret << '\n';
	
	return 0;

}