#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
vector<int>in[1000001];
vector<int>t[1000001];
int dp[1000001][2];

int DFS(int cur, int be) {
	if (t[cur].empty()) {
		if (be == 1)return 1;
		else return 0;
	}

	int& ret = dp[cur][be];
	if (ret != -1)return ret;

	if (be == 1) {
		ret = 1;
		for (int i = 0; i < t[cur].size(); i++) {
	
			int next = t[cur][i];
		

			ret += min(DFS(next, 1), DFS(next, 0));
		}
		return ret;
	}

	else if (be == 0) {
	
		int& ret = dp[cur][0];
		if (ret != -1)return ret;
		ret = 0;

		for (int i = 0; i < t[cur].size(); i++) {
	
			int next = t[cur][i];
			ret += DFS(next, 1);
			
		}

	
		return ret;
	}
}
void tree(int r, int p) {
	if (p != -1)t[p].push_back(r);
	
	for (int n : in[r]) {
		if (n == p)continue;
		tree(n, r);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	memset(dp, -1, sizeof(dp));

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		in[u-1].push_back(v-1);
		in[v-1].push_back(u-1);

	}
	tree(0, -1);

	int ans = min(DFS(0, 1), DFS(0, 0));
	cout << ans << '\n';
	return 0;

}