#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int T;
int N, M, W;



int dist[501];
const int INF = 0x3f3f3f3f;
void solve(vector<P> adj[]) {

	
	memset(dist, INF, sizeof(dist));
	bool f = false;
	dist[1] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				int to = adj[j][k].first;
				int d = adj[j][k].second;
				if (dist[to] > dist[j] + d) {
					dist[to] = dist[j] + d;
					if(i == N - 1) {
						f = true;
					}
				}
			}

		}

		
	}
	if (f == true)cout << "YES\n";
	else cout << "NO\n";

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		vector<P> adj[501];
		cin >> N >> M >> W;
		int a, b, c;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });


		}
	
		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			adj[a].push_back({ b,-c });

		}

		solve(adj);
	}
	return 0;

}