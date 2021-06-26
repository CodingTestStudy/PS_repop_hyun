#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int K;
int V, E;	
vector<int> adj[20001];
int color[20001];
bool visited[20001];

bool check() {
	
	for (int i = 1; i <= V; i++) {
		int col = color[i];
		for (int next : adj[i]) {
			
			if (color[next] == col) {
				return false;
			}
		
		}
	}

	return true;

}

void DFS(int cur,int col) {
	
	visited[cur] = true;
	color[cur] = col;

	for (int next : adj[cur]) {
		
		if (!visited[next]) {

			DFS(next,(col ^ 1));
			
		}
	}

}

void solve() {
	for (int i = 1; i <= 20000; i++) {
		adj[i].clear();
	}
	memset(color, -1, sizeof(color));
	memset(visited, 0, sizeof(visited));

	cin >> V >> E;
	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		
	}
	
	for (int i = 1; i <= V; i++) {
		if(!visited[i])DFS(i, 0);
	
	}
	
	

	bool isBi;
	isBi = check();

	if (isBi)cout << "YES\n";

	else cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> K;
	
	for (int t = 0; t < K; t++) {
		solve();
	}
	return 0;

}