#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> v;
string s;
int ans = 0;
bool isExist[11] = {false};
int arr[27] = {0};
void permu(int ii, int n) {

	if (ii == n) {
		bool check = true;
		char ex = v[0];
		
		for (int i = 1; i < v.size(); i++) {
			if (ex == v[i]) {
				check = false;
				break;
			}
		
			ex = v[i];

		}
		
		if (check)++ans;

		return;
	}

	for (int i = 0; i < n; i++) {
		
		if (isExist[i] == true)continue;
		isExist[i] = true;
		v.push_back(s[i]);
		permu(ii + 1, n);
		v.pop_back();

		isExist[i] = false;
		
	}
	
}

int fact(int a) {
	
	if (a == 0 || a == 1)return 1;

	return a * fact(a - 1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 97]+= 1;
	}

	permu(0, s.length());
	
	for (int i = 0; i <= 26; i++) {
		ans = ans / fact(arr[i]);
	}
	cout << ans << '\n';
	return 0;

}
