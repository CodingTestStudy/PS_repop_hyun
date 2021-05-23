#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;
int N, M;
const int INF = 0x3f3f3f3f;
int minCost = INF;
vector<pair<int, int>> arr;
int val[101];
int cost[101];
int dp[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; i++) {

		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}

	}

	int j = 0;
	for (j=0; j <= sum && dp[j] < M; j++) {
		
	}
	cout << j << '\n';
	return 0;

}