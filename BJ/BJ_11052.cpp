#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = -987654321;
int N;
int dp[1001];
int arr[1001];
int cnt[1001];
int DP(int n) {

	if (n == 0)return 0;
	if (n < 0)return INF;

	int& ret = dp[n];
	if (ret != -1)return ret;

	for (int i = 1; i <= n; i++) {
		ret = max(DP(n - i) + arr[i], ret);
	}


	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cnt[i] = i;
	}

	dp[1] = arr[1];

	int ans = DP(N);

	cout << ans << '\n';
	return 0;

}