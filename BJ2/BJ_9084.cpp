#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int T;
int N, M;
int dp[10001];
int coin[21];
void solve() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= M; j++) {
			
			dp[j] += dp[j - coin[i]];
		
		}

	}


	cout << dp[M] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		memset(coin, 0, sizeof(coin));
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
	
			cin >> coin[i];
		}
		cin >> M;
		solve();
	}
	
	
	return 0;

}