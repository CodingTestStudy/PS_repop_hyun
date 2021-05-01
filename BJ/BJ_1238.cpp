//백준 1238 silver cow party
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int cost[1001][1001];
vector<int>adj[1001];
int N, M, X;
int ans = -INF;

int revDaik(int start, int end) {
	int dist[1001];
	memset(dist, INF, sizeof(dist));
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0,start });
	bool visited[1001] = { 0 };

	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while ((!pq.empty() && visited[cur]));

		if (visited[cur])break;

		visited[cur] = true;

		for (int a : adj[cur]) {
			int next = a;
			int d = cost[cur][next];

			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push({ dist[next],next });

			}
		}
		if (cur == end)break;
	}

	return dist[end];
}
int daik(int start,int end) {

	int dist[1001];
	memset(dist, INF, sizeof(dist));
	dist[start] = 0;
	priority_queue<pair<int,int>, vector<pair<int, int>>,greater<>> pq;
	pq.push({ 0,start });
	bool visited[1001] = { 0 };
	
	while (!pq.empty()) {
		int cur;
		
		do {
			cur = pq.top().second;
			pq.pop();
		} while ((!pq.empty() && visited[cur]));

		if (visited[cur])break;

		visited[cur] = true;
		
		for (int a: adj[cur]) {
			int next = a;
			int d = cost[cur][next];
			
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push({ dist[next],next });

			}
		}

		if (cur == end)break;
	}

	return revDaik(end, start) + dist[end];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(cost, INF, sizeof(cost));

	cin >> N >> M >> X;
	int here, to;
	int d;
	for (int i = 0; i < M; i++) {
		cin >> here >> to >> d;
		cost[here][to] = min(cost[here][to], d);
		adj[here].push_back(to);

	}


	for (int i = 1; i <= N; i++) {
		ans = max(ans,daik(i,X));
	}
	

	cout << ans << '\n';
	return 0;

}