#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int dp[10000 + 10];
int arr[1000 + 10];
vector<int> v;
int N, M;
#define INF 0x3f3f3f3f

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	
	}
	arr[0] = 0;

	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j <= M; j++) {
			int t = arr[i] + arr[j];
			if (t <= N) {
				v.emplace_back(t);
				dp[t] = 1;
			}
		
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int e : v) {

		for (int i = e + 1; i <= N; i++) {
			if (dp[i - e] == 0)continue;
			if (dp[i] == 0 || dp[i] > dp[i - e] + 1)
				dp[i] = dp[i - e] + 1;
		}
	}

	if (dp[N] == INF)cout << -1 << '\n';
	else cout << dp[N] << '\n';

	return 0;

}
