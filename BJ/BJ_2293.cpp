//백준 2293 동전1
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
int n, k;
ll dp[10001];
ll arr[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	arr[0] = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	sort(arr+1, arr+1 + n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= arr[i])dp[j] += dp[j - arr[i]];
		}

	}
	
	cout << dp[k] << '\n';
	return 0;

}