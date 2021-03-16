//백준 2206 벽 부수고 이동하기
#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
const int INF = 0x3f3f3f3f;
int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };
int ret = INF;
int N, M;

int arr[1001][1001];
int ans[1001][1001][2];
bool discoverd[1001][1001][2];

void BFS() {

	memset(discoverd, 0, sizeof(discoverd));
	memset(ans, INF, sizeof(ans));
	ans[0][0][1] = 1;
	
	queue<pair<pair<int, int>, int>> q;
	q.push({{ 0,0 },1});
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];
			if (0 <= n_y && n_y < N && 0 <= n_x && n_x < M) {
				if (!discoverd[n_y][n_x][b] && arr[n_y][n_x] == 0) {
					discoverd[n_y][n_x][b] = 1;
					ans[n_y][n_x][b] = ans[y][x][b] + 1;
					q.push({ { n_y,n_x },b });

				}

				if (arr[n_y][n_x] == 1 && b == 1) {
					discoverd[n_y][n_x][b-1] = 1;
					ans[n_y][n_x][b-1] = ans[y][x][b] + 1;
					q.push({ { n_y,n_x },b-1 }); //부수고 간다.
				}
			}
		}
	}

	int ret = min(ans[N - 1][M - 1][0],ans[N-1][M-1][1]);
	if (ret == INF)cout << -1 << '\n';
	else cout << ret << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	string in;
	for (int i = 0; i < N; i++) {
		cin >> in;
		for (int j = 0; j < M; j++) {
			if (in[j] == '0') {
				arr[i][j] = 0;
				
			}
			else if (in[j] == '1') {
				arr[i][j] = 1;
			
			}
		}
	}

	BFS();

}
