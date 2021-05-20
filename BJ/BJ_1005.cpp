//백준 1005 ACM Craft
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int indeg[1000 + 1];
int ret[1000 + 1];
int t[1000 + 1];
int T;
int N, K;
int goal;
vector<int> adj[1000 + 1];

void solve() {

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}


	while (!q.empty()) {

		int cur = q.front(); q.pop();
		
		ret[cur] += t[cur];
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			int m=max(ret[next], ret[cur]);
			ret[next] = m;

			indeg[next]--;

			if (indeg[next] == 0)q.push(next);
		}
		

	}

	cout << ret[goal] << '\n';
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		memset(indeg, 0, sizeof(indeg));
		memset(ret, 0, sizeof(ret));
		memset(t, 0, sizeof(t));
		for (int i = 0; i < 1000 + 1; i++) {
			adj[i].clear();
		}
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {

			cin >> t[i];
		}

		for (int i = 1; i <= K; i++) {
			int from, to;
			cin >> from >> to;
			
			adj[from].push_back(to);
			indeg[to] += 1;
		}

		cin >> goal;

		solve();
	}
	return 0;

}