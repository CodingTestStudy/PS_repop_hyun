#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

using P = pair<int, int>;
int T;
int N;
int yy[8] = { -1,-1,0,1,1,1,0,-1 }; //12시부터 시계 
int xx[8] = { 0,1,1,1,0,-1,-1,-1 };
int arr[3][102];
bool visited[3][102];
void solve() {
	memset(arr, 0, sizeof(arr)); memset(visited, 0, sizeof(visited));
	cin >> N;
	string inn;
	for (int i = 0; i < 2; i++) {
		cin >> inn;
		for (int j = 0; j < inn.length(); j++) {
			if (inn[j] == '1') {
				arr[i][j] = 1;
			}
			
		}
	}

	queue<P> q;
	q.push({ 0,0 });
	bool flag = 0;
	while (!q.empty()) {

		P cur = q.front();
		q.pop();

		if (cur.first == 1 && cur.second == N - 1) {
			flag = 1; break;
		}
		for (int i = 0; i < 8; i++) {
			int n_y = cur.first + yy[i];
			int n_x = cur.second + xx[i];
			if (0 <= n_y && n_y < 2 && 0 <= n_x && n_x < N) {
				if (!visited[n_y][n_x] && arr[n_y][n_x] != 1) {
					visited[n_y][n_x] = 1;
					q.push({ n_y,n_x });
				}

			}
			
			
		}

	}


	if (flag) {
		cout << "YES\n";

	}
	else cout << "NO\n";

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++) {

		solve();
	}
	return 0;

}