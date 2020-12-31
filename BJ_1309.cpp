#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
ll dp[100001][3];
ll N;
ll ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	ret = dp[N-1][0] + dp[N-1][1] + dp[N-1][2];
	cout << ret % 9901 << '\n';
	return 0;
}