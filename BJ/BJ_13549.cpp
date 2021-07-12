//백준 13549
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int visited[100000 + 1];
queue<pair<int,int>> q;
int N, K;
int ans = 0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(visited, false, sizeof(visited));

	cin >> N >> K;
	q.push({ N,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == K) {
			ans = cnt;
			break;
		}

		if (2 * x <= 100000) {
			if (!visited[2 * x]) {
				q.push({ 2 * x,cnt });
				visited[2 * x] = true;
			}
		}

		if (x - 1 >= 0) {
			if (!visited[x - 1 ]) {
				q.push({ x -1 ,cnt + 1 });
				visited[x - 1 ] = true;
			}
		}

		if (x + 1 < 100001) {
			if (!visited[x + 1]) {
				q.push({ x + 1,cnt + 1 });
				visited[x + 1] = true;
			}
		}
		

	}

	cout << ans << '\n';
	return 0;

}