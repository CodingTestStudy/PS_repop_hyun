
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
int N;
int dp[100001][10];
int val[100001];
vector<int> adj[100001];
vector<int> t[100001];

void make_t(int r, int p) {
	if (p != -1)t[p].push_back(r);

	for (int n : adj[r]) {
		if (n == p)continue;
		make_t(n, r);
	}

}

int dfs(int cur, int num) {


	int &ret = dp[cur][num];
	if (ret != -1)return ret;

	ret = (val[cur] == num);

	for (int next : t[cur]) {
		if (val[cur] == num) {
			for (int i = num; i < 10; i++) {
				ret += (dfs(next, i) % MOD);
			}
		}
		ret += (dfs(next, num) % MOD);
	}

	return ret %= MOD;


}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}
	int ans = 0;
	make_t(1,-1);


	for (int i = 0; i < 10; i++) {
		ans += dfs(1, i);
	}

	cout << ans % MOD << '\n';

	return 0;

}
