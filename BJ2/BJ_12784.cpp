#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;
int T;
int N, M;
int ans;

vector<P>adj[1001];
vector<P>t[1001];


void input() {
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		
	}
}
void init() {
	
	ans = 0;
	for (int i = 1; i <= 1000; i++) {
		adj[i].clear();
		t[i].clear();
	}
}
void make_t(int r, int p,int cost) {

	if (p != -1)t[p].push_back({ r,cost });

	for (P s : adj[r]) {
		if (p == s.first)continue;
		make_t(s.first, r, s.second);
	}

}
int dfs(int cur, int curCost) {
	if (t[cur].empty()) {
		return curCost;
	}
	
	int sum = 0;
	
	for (int i = 0; i < t[cur].size(); i++) {
		int next = t[cur][i].first;
		int n_cost = t[cur][i].second;
		sum += dfs(next, n_cost);
	}

	return min(sum, curCost);

}
int solve() {
	init();
	input();
	make_t(1,-1,INF);
	
	ans = dfs(1, INF);
	if (ans == INF) {
		ans = 0;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {

		cout << solve() << '\n';
	}
	return 0;

}
