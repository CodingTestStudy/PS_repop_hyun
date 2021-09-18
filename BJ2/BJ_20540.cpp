#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
string a;

vector<char>v1;
vector<char>v2;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	v1.push_back('E');
	v1.push_back('S');
	v1.push_back('T');
	v1.push_back('J');

	v2.push_back('I');
	v2.push_back('N');
	v2.push_back('F');
	v2.push_back('P');

	
	cin >> a;
	string ans = "";
	for (int i = 0; i < 4; i++) {

		if (v1[i] == a[i]) {

			ans.push_back(v2[i]);
		}
		else if (v2[i] == a[i]) {

			ans.push_back(v1[i]);

		}

	}

	cout << ans << '\n';
	return 0;

}
