#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;

vector<p> adj[101];
int it[101];
bool visited[101];
bool fin[101];
int n,m,r;
const int INF = 0x3f3f3f3f;

int itemSum;
void  DFS(int cur,int range) {//현재 위치, 아이템 합, 남은 수색거리

	//못오는 곳임
	if (range < 0) {
		
		return;

	}

	visited[cur] = true; //방문
	for (p s : adj[cur]) {
		int next = s.first;
		int d = s.second;
		if (!visited[next]) {
			
			DFS(next,range - d);
			
		}
		
	}
	
	visited[cur] = false;
	fin[cur] = true;
	

}

int solve(int dropped) {
	itemSum = 0;
	memset(visited, 0, sizeof(visited));
	memset(fin, 0, sizeof(fin));
	DFS(dropped,m);

	for (int i = 1; i <= n; i++) {
		if (fin[i]) {
			itemSum += it[i];
		}
	}
	return itemSum;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> it[i];
	}
	int a, b, c;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		
	}
	int ret = -1;
	for (int i = 1; i <= n; i++) {
		ret = max(solve(i), ret); 
		
	}

	cout << ret << '\n';
	return 0;

}