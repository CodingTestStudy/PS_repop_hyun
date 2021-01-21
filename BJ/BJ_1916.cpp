//백준 1916 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 987654321
int N,M;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
int dist[1001];
bool visited[1001];
int a, b, c; //a to b , cost
int from, to;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	fill(dist, dist+N , INF);
	fill(visited, visited+N, false);
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		v[a-1].push_back({ b-1,c });

	}

	cin >> from >> to;
	dist[from-1] = 0;
	q.push({ dist[from-1],from-1 });
	while (!q.empty()) {
		int cur;
		while (1) {
			cur = q.top().second; //현재 정점 번호
			q.pop();
			if(q.empty()|| visited[cur] == false)break;
			
		}
		if(visited[cur])break;
		visited[cur] = true;
		
		for (pair<int, int> p: v[cur]) { //인접한 정점 dist 테이블 갱신
		
			dist[p.first] = min(dist[p.first], p.second + dist[cur]);  //or cost + 현재 정점까지 최소 비용
			q.push({ dist[p.first],p.first });
		}
		
	}

	cout << dist[to-1] << '\n';
	return 0;

}