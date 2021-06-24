//백준 1240 노드사이의 거리
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int N, M;
int dist[1001];
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1001];
void daik(int st,int ed){
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> pq;
	memset(dist, INF, sizeof(dist));
	dist[st] = 0;
	pq.push({ 0,st });

	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();

		for (pair<int, int> p : adj[node]) {
			int next = p.first;
			int d = p.second;

			if (dist[next] > dist[node] + d) {
				dist[next] = dist[node] + d;
				pq.push({ dist[next],next });
			}
		
		}

	}
	
	
	cout << dist[ed] << '\n';

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });

	}
	
	for (int i = 0; i < M; i++) {
		
		cin >> a >> b;

		daik(a, b);
	}
	return 0;

}
