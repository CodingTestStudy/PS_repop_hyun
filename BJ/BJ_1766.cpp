#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int N, M;
priority_queue<int, vector<int>, greater<>> pq;
int deg[32000 + 1];
vector<int> adj[32000 + 1];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(deg, 0, sizeof(deg));
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]+=1;
	}

	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0)pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << cur << ' ';
		for (int next : adj[cur]) {
			deg[next] -= 1;
			if (deg[next] == 0)pq.push(next);

		}

	}
	return 0;

}