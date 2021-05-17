//백준 1918 후위표기식

#include <iostream>
#include <string>
#include <stack>
using namespace std;
string input;

stack<char> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> input;
	string ans = "";
	for (int i = 0; i < input.length(); i++) {
		
		if ('A'<= input[i] && input[i] <= 'Z') ans +=input[i];

		else {
			if (input[i] == '(') {
				s.push(input[i]);

			}
			else if (input[i] == '*' || input[i] == '/') {
		
				while (!s.empty() && (s.top() == '*' || s.top() == '/') ) {
			
					
					ans += s.top();
					s.pop();
				}
				s.push(input[i]);
				
			}
			else if (input[i] == '+' || input[i] == '-') {
		
			
				while (!s.empty() && s.top() != '(' ) {
						ans += s.top();
						s.pop();
				}
				s.push(input[i]);
				
			}
			else if (input[i] == ')') {
				
				while ( !s.empty() &&s.top() != '(' ) {
					
					ans += s.top();
					s.pop();
				}
				s.pop();
			}
		
		}
	}

	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans << '\n';
	return 0;

}