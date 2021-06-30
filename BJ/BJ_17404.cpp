#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N;
int dp[1000 + 2][1000 + 2];
int arr[1000 + 1][3];
const int MAX = 0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = MAX;
	cin >> N;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}

	}

	for (int k = 0; k < 3; k++) {
		
		//첫번째 집 색 선택
		for (int i = 0; i < 3; i++) {
			if (i == k)dp[0][i] = arr[0][i];
			else dp[0][i] = MAX;
		}

		for (int i = 1; i < N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];

		}
		for (int i = 0; i < 3; i++) {
			if (k != i) {
				ans = min(ans, dp[N - 1][i]);
			}
		}

	}
	cout << ans << '\n';
	
	return 0;

}
