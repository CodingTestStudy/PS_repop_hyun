#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 100
#define MAXM 50
int N, M;
int sum[MAXN + 1];
int arr[MAXN + 1];
int dp[MAXN+1][MAXN + 1];
const int INF = 0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}


	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int j = 1; j <= M; j++) {
		dp[0][j] = -INF;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			
			dp[i][j] = dp[i - 1][j];

			for (int k = 1; k <= i; k++) {
				if (k >= 2) {
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
				}
				
				//3번째 까지에서 구간 1개일때
				else if (k == 1 && j == 1) {
					dp[i][j] = max(dp[i][j], sum[i]);
				}

			}
		}
	}

	cout << dp[N][M] << '\n';
	return 0;

}