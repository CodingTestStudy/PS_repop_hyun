//백준 1738 골목길
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int INF = -987654321;
vector<pair<int, int>> adj[101];
vector<int> rev[101]; // 도착점으로부터 역으로 도달할 수 있는 노드들
bool visited[101] = { false };

int n, m;
int dist[101];
int prv[101];
bool isCycle = false;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;

		adj[u - 1].push_back({ v - 1 ,w });
		rev[v - 1].push_back(u - 1);//거꾸로
	}
	fill(dist, dist + n, INF);
	dist[0] = 0;

	queue<int>q;
	q.push(n-1);
	visited[n - 1] = true;

	while (!q.empty()) { //출발점으로 부터 DFS로 도달가능한 노드 체크 
		int idx = q.front();//거꾸로
		
		q.pop();
		for (int i = 0; i < rev[idx].size(); i++) {
			int next = rev[idx][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			for (pair<int, int> p : adj[j]) {
				int next = p.first;
				int cost = p.second;
				if (dist[j] != INF && dist[next] < dist[j] + cost) {
					dist[next] = dist[j] + cost;
					prv[next] = j; //경로 탐색용
					if (i == n - 1 && visited[next] == true) {
						isCycle = true;
					}
					
				}
			}
			
		}
	}
	
	if (isCycle) {
		cout << -1 << '\n';
	}

	else {
		vector<int>ans;
		int idx = n-1;
		while(1){
			ans.push_back(idx + 1);
			if (idx == 0) break;
			else idx = prv[idx];
		}
		
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
	}

	return 0;

}