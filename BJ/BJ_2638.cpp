/백준 2638 치즈
//구현 연습
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <algorithm>
using namespace std;
//상하좌우
int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };

bool visited[101][101];
int N, M;
int arr[101][101];

int ans = 0;
queue<pair<int, int>> q;
queue<pair<int,int>> tmp;
void DFS(int y, int x) {
	visited[y][x] = true;
	arr[y][x] = -1; //외부공기
	for (int i = 0; i < 4; i++) {
		int n_y = y + yy[i];
		int n_x = x + xx[i];
		if (0 <= n_y && n_y < N && 0 <= n_x && n_x < M) {
			if (!visited[n_y][n_x] && arr[n_y][n_x] != 1) {
				DFS(n_y, n_x);
			}
		}
	}
}

//주변 체크 
int counting(int y,int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int n_y = y + yy[i];
		int n_x = x + xx[i];
		//외부 공기 접촉면 수 리턴
		if (arr[n_y][n_x] == -1) {
			cnt++;
		}
	}

	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(visited, false, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tmp.push({ i,j });
			}
		}
	}


	while (1) {
		memset(visited, false, sizeof(visited));
		DFS(0, 0); //외부공기 파악
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
				if (arr[i][j] == 1) {
					int cnt = 0;
					cnt = counting(i, j);

					if (cnt >= 2){
						arr[i][j] = 3;//녹을것 미리 체크
						flag = true;
					}

				}

			}
		}
		
		//녹을것 존재할때
		if (flag) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (arr[i][j] == 3) { //실제로 녹여줌
						arr[i][j] = -1;
					}
				}
			}

		}
		++ans;

		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					flag = true;
				}
			}
		}

		if (!flag)break;
		
	}

	cout << ans << "\n";


	return 0;

}
