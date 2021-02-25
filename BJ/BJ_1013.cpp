
// 백준 1013 Contact
#include <iostream>
#include <string>
#include <regex>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	regex re("(100+1+|01)+");

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string inn;
		cin >> inn;

		if (regex_match(inn, re)) {
			cout << "YES" << '\n';
		}

		else cout << "NO" << '\n';
		
	}
	return 0;

}
