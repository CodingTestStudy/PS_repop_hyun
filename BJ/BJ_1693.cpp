//백준 1693 트리 색칠하기
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
const int INF = 0x3f3f3f3f;
int p[100002];
vector<int>in[100002];
vector<int>t[100002];
int dp[100002][20];
int DFS(int cur,int color) {

	int& ret = dp[cur][color];
	if (ret != -1)return ret;
	
	ret = p[color];
	if (t[cur].empty()) {
		return ret;
	}

	for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			int tmp = INF;
			for (int j = 1; j <= 20; j++) {
				if (color == j)continue;
				tmp = min(tmp,DFS(next, j));
			}

			ret += tmp;
	}

	return ret;


}

void make_t(int root, int par) {

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
	for (int i = 1; i <= 20; i++) {
		p[i] = i;
	}
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		in[u].push_back(v);
		in[v].push_back(u);
	}

	make_t(1, 0);
	int ans = INF;
	for (int i = 1; i <= 20; i++) {
		ans = min(DFS(1, i), ans);
	}
	cout << ans << '\n';
	return 0;

}