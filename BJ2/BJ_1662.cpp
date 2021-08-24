#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
int func() {
	int ret = 0;
	while (s.top() != '(') {

		if (s.top() == ')') {
			s.pop();
			ret += func();
		}
		else {
			s.pop();
			ret += 1;
		}

	}
	s.pop();
	ret *= (s.top() - '0');
	s.pop();
	return ret;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string S;
	cin >> S;
	
	for (int i = 0; i < S.length(); i++) {
		s.push(S[i]);
	}
	
	int ans = 0;

	while (!s.empty()) {

		if (s.top() == ')') {
			s.pop();
			ans +=func();
		}
		else {
			s.pop();
			ans += 1;
		}

	}
	

	cout << ans << '\n';
	return 0;

}
