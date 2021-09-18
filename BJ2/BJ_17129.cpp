#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int n, m;
typedef pair<int, int> P;
int arr[3000 + 1][3000 + 1];
int cnt[3000 + 1][3000 + 1];
bool visited[3000 + 1][3000 + 1];

int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };

queue<P>q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, false, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string r;
		cin >> r;
		for (int j = 0; j < m; j++) {

			arr[i][j] = r[j] - '0';
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		}
		

	}
	int ans = -1;
	int c = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (arr[y][x] != 1 && arr[y][x] != 0 && arr[y][x] != 2) {
			ans = cnt[y][x];
			break;
		}
		

		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];

			if (0 <= n_y && n_y < n && 0 <= n_x && n_x < m) {

				if (!visited[n_y][n_x] && arr[n_y][n_x] != 1) {
					visited[n_y][n_x] = true;
					q.push({ n_y,n_x });
					cnt[n_y][n_x] = cnt[y][x]+1;

				}
			}

		}
		

	}
	

	if (ans == -1) {
		cout << "NIE\n";
	}
	else {

		cout << "TAK\n";
		cout << ans << '\n';
	}

	return 0;

}