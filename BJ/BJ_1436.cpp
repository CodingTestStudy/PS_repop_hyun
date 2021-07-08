#include <iostream>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
int N;

typedef long long ll;
ll ans;
bool check(ll n) {

	string s = to_string(n);
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6') {
			c += 1;
		}

		else c = 0;

		if (c == 3)break;
	}

	if (c == 3)return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	ans = 666;
	int cnt = 0;
	while (1) {

		bool flag = check(ans);


		if (flag)cnt += 1;
		if(cnt == N)break;

		ans += 1;
	}


	cout << ans << '\n';
	
	return 0;

}