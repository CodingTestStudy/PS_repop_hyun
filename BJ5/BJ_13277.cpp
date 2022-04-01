#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
int T;

string cal(char a, char b,char upper) {
	
	if (upper == '0') {
		if (a == '0' && b == '0')return "0";
		if (a == '1' && b == '0')return "1";
		if (a == '0' && b == '1')return "1";
		if (a == '1' && b == '1')return "10";
		
	}

	else if (upper == '1') {
		if (a == '0' && b == '0')return "1";
		if (a == '1' && b == '0')return "10";
		if (a == '0' && b == '1')return "10";
		if (a == '1' && b == '1')return "11";

	}

}
void solve() {
	string ans = "";
	string a, b;

	cin >> a >> b;
	//앞의 0처리
	int aCheck=0, bCheck=0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '0')break;
		else aCheck++;
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] != '0')break;
		else bCheck++;
	}
	a = a.substr(aCheck);
	b = b.substr(bCheck);

	if (a == "" && b == "") {
		cout << "0" << '\n';
		return;
	}


	if (a.length() < b.length())swap(a, b);
	int aLength = a.length(); //항상 길다
	int bLength = b.length();
	int dist = aLength - bLength;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while(dist--) b.push_back('0');

	int i = 0;
	char carry = '0';
	while (i < a.length()) {
		
		string ret = cal(a[i], b[i], carry);
		if (ret.length() > 1) {
			carry = ret[0];
			ans.push_back(ret[1]);
		}
		else {
			carry = '0';
			ans.push_back(ret[0]);
		}
		i++;

	}

	if (carry == '1')ans.push_back('1');

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)solve();
	return 0;

}
