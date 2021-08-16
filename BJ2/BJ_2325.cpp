#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define MAXN 1000
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
vector<P> adj[MAXN + 1];
bool isOk[MAXN + 1][MAXN + 1]; //가능한것인지
int dist[MAXN + 1];

int N, M;
int daik(int banx, int bany) { //최단거리 값 반환 
	memset(dist, INF, sizeof(dist));
	priority_queue<P,vector<P>, greater<P>>pq;
	int ans = 0;
	dist[1] = 0;
	pq.push({ 0,1 });
	
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cur == N) {
			ans = dist[cur];
			break;
		}
		if (dist[cur] < cost)continue;
		for (P n : adj[cur]) {
		
			int next = n.first;
			int c = n.second;
			if ((banx == cur && bany == next) || (banx == next && bany == cur))continue;
			if (dist[cur] + c < dist[next]) {
				dist[next] = dist[cur] + c;
				pq.push({ dist[next],next });

			}

		}




	}
	
	return ans;

}

int parent[MAXN+1];
vector<int> findPath(int n) {
	vector<int> path(1, n);
	while (parent[n] != n) {
		n = parent[n];
		path.push_back(n);
	}
	reverse(path.begin(), path.end());
	return path;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(isOk, true, sizeof(isOk));

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, z;
		cin >> a >> b >> z;
		adj[a].push_back({ b,z });
		adj[b].push_back({ a,z });


		
	}
	//최단경로 구하기
	priority_queue<P,vector<P>, greater<P>>pq;
	vector<int> rout;
	memset(dist, INF, sizeof(dist));
	dist[1] = 0;
	pq.push({ 0,1 });
	memset(parent, -1, sizeof(parent));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cur == N)break;
		if (dist[cur] < cost)continue;
		for (P n : adj[cur]) {

			int next = n.first;
			int c = n.second;
			if (dist[cur] + c < dist[next]) {
				dist[next] = dist[cur] + c;
				pq.push({ dist[next],next });
				parent[next] = cur;
			}

		}


	}


	parent[1] = 1;
	rout = findPath(N);

	int ans = 0;
	for (int i = 0; i < rout.size()-1; i++) {
		
		ans = max(ans, daik(rout[i], rout[i + 1]));


	}

	cout << ans << '\n';
	return 0;

}
