//백준 2644 촌수계산
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int> arr[101];
int val[101];
bool visited[101];
int n, m;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int st, ed;
	memset(visited, 0, sizeof(visited));
	memset(val, 0, sizeof(val));
	cin >> n;
	cin >> st >> ed;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		arr[x-1].push_back(y-1);
		arr[y-1].push_back(x-1);
	}
	
	queue<int> q;
	q.push(st-1);
	visited[st - 1] = true;
	while (!q.empty()) {
		int cur = q.front();
		
		q.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i];
			
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				val[next] = val[cur] + 1;
			}
		}
	}

	if (val[ed - 1] == 0)cout << -1 << '\n';
	else cout << val[ed - 1] << '\n';
	return 0;

}
