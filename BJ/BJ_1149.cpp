#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int arr[1001][3];
int dp[1001][3];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	}
	
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	cout << min(dp[N][2], min(dp[N][0], dp[N][1]))<< '\n';
	return 0;

}
