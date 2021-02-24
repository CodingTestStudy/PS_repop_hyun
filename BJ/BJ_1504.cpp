/*
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std; 
vector<pair<int, int>>adj[801];
const int INF = 987654321;
int dist[801];
bool visited[801];
int N, E;
int daik(int start,int end) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	dist[start] = 0;

	q.push({ 0,start }); //dist최소,정점 번호
	while (!q.empty()) {

		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur] == true);

		if (visited[cur] == true)break;
		visited[cur] = true;

		for (pair<int, int> p : adj[cur]) {
			int next = p.first;
			if (dist[next] > dist[cur] + p.second) {
				dist[next] = dist[cur] + p.second;
				q.push({ dist[next],next });

			}
		}


	}
	if (dist[end] == INF)return -987654321;
	return dist[end];

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		
		adj[a - 1].push_back({ b - 1,c });
		adj[b - 1].push_back({ a - 1,c });

	}
	int v1, v2;
	cin >> v1 >> v2;

	int ret = 0;

	

	ret = min(daik(0,v1-1),daik(0,v2-1));
	if (ret < 0) {
		cout << -1 << '\n';
		return 0;
	}


	
	if (ret == daik(0, v1 - 1)) {
		
	
		ret += daik(v2 - 1, N-1);
		if (ret < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}

	else if(ret == daik(0, v2 - 1)){
	
		ret += daik(v1 - 1, N - 1);
		if (ret < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}


	cout << ret << '\n';

	

	return 0;

}

*/


//백준 1504 특정한 최대 경로
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std; 
vector<pair<int, int>>adj[801];
const int INF = 987654321;
int dist[801];
bool visited[801];
int N, E;
vector<int> daik(int start,int end) {
	vector<int> dist(end + 1, INF);
	fill(visited, visited + N, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	dist[start] = 0;

	q.push({ 0,start }); //dist최소,정점 번호
	while (!q.empty()) {

		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur] == true);

		if (visited[cur] == true)break;
		visited[cur] = true;

		for (pair<int, int> p : adj[cur]) {
			int next = p.first;
			if (dist[next] > dist[cur] + p.second) {
				dist[next] = dist[cur] + p.second;
				q.push({ dist[next],next });

			}
		}


	}
	return dist;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		
		adj[a - 1].push_back({ b - 1,c });
		adj[b - 1].push_back({ a - 1,c });

	}
	int v1, v2;
	cin >> v1 >> v2;





	vector<int> ret = daik(0, N - 1);
	vector<int> tmp1 = daik(v1 - 1, N - 1);
	vector<int> tmp2 = daik(v2 - 1, N - 1);


	int ans = min(ret[v1 - 1] + tmp1[v2 - 1] + tmp2[N - 1], ret[v2 - 1] + tmp2[v1 - 1] + tmp1[N - 1]);
	
	if (ans >= INF || ans < 0)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;

}

