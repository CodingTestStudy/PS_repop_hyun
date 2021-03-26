//백준 1949 우수마을

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int p[10002];
vector<int>in[10002];
vector<int>t[10002];
int dp[10002][2];
int DFS(int cur, int excel) {
	
	int& ret = dp[cur][excel];
	if (ret != -1)return ret;

	if (t[cur].empty()) {
		if (excel == 1)return p[cur];
		else return 0;
	}

	if (excel == 1) {
		ret = p[cur];
		
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			ret += DFS(next, 0);
		}
		return ret;

	}

	else if (excel == 0) {
		ret = 0;
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			ret += max(DFS(next, 1),DFS(next,0));
		}

		return ret;
	}

}

void make_t(int root,int par) {
	
	if (par != 0)t[par].push_back(root);

	for (int next : in[root]) {
		if (next == par)continue;
		make_t(next, root);
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		in[u].push_back(v);
		in[v].push_back(u);
	}

	make_t(1, 0);

	int ans = max(DFS(1, 1), DFS(1, 0));

	cout << ans << '\n';
	return 0;

}
