//백준 15591 MooTube
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

vector<pair<int,int>> t[5001];
int N, Q;
int v,k;
bool visited[5001];
int DFS(int cur, int now) {
	int cnt = 0;
	visited[cur] = true;
	if (now >= k)cnt++;

	else if (now == -1) {
		now = 987654321;
	}

	for (int i = 0; i < t[cur].size(); i++) {
		int next = t[cur][i].first; 
		int cost = t[cur][i].second;
		if (visited[next])continue;
		if(cost > now)
		{
			cnt += DFS(next, now);
		}
		else {
			cnt += DFS(next, cost);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	int cost;
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> cost;
		t[u].push_back({ v ,cost });
		t[v].push_back({ u ,cost });
	}

	for (int i = 0; i < Q; i++) {
		cin >> k >> v;
		memset(visited, 0, sizeof(visited));
		cout << DFS(v,-1) << '\n';
	}
	
	return 0;

}