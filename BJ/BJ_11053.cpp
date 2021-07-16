#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int ans = 0;
void solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			int cur = arr[i];
			if (arr[j] < cur) {
				dp[i] = max(dp[i], dp[j] + 1);

			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill_n(dp,1001, 1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	solve();
	return 0;

}
