#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int arr[2][100000 + 1];
int dp[2][100000 + 1];
int T, n;
int ret = 0;

void solve() {
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];

	for (int j = 2; j <= n; j++) {
		dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + arr[0][j];
		dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + arr[1][j];
	}

	cout << max(dp[0][n],dp[1][n])<< '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		ret = 0;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		solve();


	}
	return 0;

}