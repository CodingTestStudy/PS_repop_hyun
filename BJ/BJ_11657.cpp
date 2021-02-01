//백준 11657 타임머신
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> P;
const long long INF = 987654321;
vector<P> adj[501];
long long dist[501];
int N, M, A, B, C;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		
		adj[A-1].push_back({ B-1,C });
	}
	bool Isminus = false; //음의 사이클 존재하면 -1출력해야됨
	fill(dist, dist + N, INF);
	dist[0] = 0; //시작 지점 거리 0
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < N; j++) {
			
			for (P s : adj[j]) {
				int next = s.first;
				int cost = s.second;
				if (dist[j] != INF && dist[next] > dist[j] + cost) { //거리갱신
					dist[next] = dist[j] + cost;
					if (i == N - 1)Isminus = true;
				}
			}
		}
	}
	
	if (Isminus == true)cout << -1 << '\n';
	else {
		for (int i = 1; i < N; i++) {
			if (dist[i] == INF)cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	return 0;

}