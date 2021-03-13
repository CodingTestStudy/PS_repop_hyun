//백준 10844 쉬운 계단 수
#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
int N;
ll dp[11][101];
ll DP(int cur, int cnt) {

	if (cur < 0 || cur >= 10) return 0;
	if (cnt == 0)return 1;
	
	ll& ret = dp[cur][cnt];
	if (ret != -1)return ret % 1'000'000'000;

	return ret = (DP(cur + 1, cnt - 1) + DP(cur - 1, cnt - 1)) % 1'000'000'000;

	

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> N;
	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += DP(i, N-1) % 1'000'000'000;
	}

	cout << ans % 1'000'000'000 << '\n';
	return 0;

}