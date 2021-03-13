//백준 3055 SLIKAR
#include <iostream>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;
const int MAX = 0x3f3f3f3f;
int R, C;
int arr[51][51];
int water[51][51];
pair<int, int> st;
pair<int, int> ed;

queue<pair<int, int>> waterSt;

int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };


void solve() {
	
	while (!waterSt.empty()) {
		int y = waterSt.front().first;
		int x = waterSt.front().second;
		waterSt.pop();
		
		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];

			if (0 <= n_y && n_y < R && 0 <= n_x && n_x < C) {
				if (water[n_y][n_x] == 0) {
					water[n_y][n_x] = water[y][x] + 1;
					waterSt.push({ n_y,n_x });
				}
			}
		}

	}

	queue<pair<int, int>> q;
	q.push(st);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];

			if (0 <= n_y && n_y < R && 0 <= n_x && n_x < C) {
				if( arr[n_y][n_x] == 0) {
					arr[n_y][n_x] = arr[y][x] + 1;
					//못가는 부분임
					if (arr[n_y][n_x] >= water[n_y][n_x] - 1 && water[n_y][n_x] != 0) {
						continue;
						arr[n_y][n_x] = 1;
					}
					else {
						//갈 수 있는 부분만 큐에 넣고 BFS
						q.push({ n_y,n_x });
					}
				}
			}
		}

	}

	int eY = ed.first;
	int eX = ed.second;

	if (arr[eY][eX] == 0)cout << "KAKTUS\n";

	else {
		cout << arr[eY][eX] << '\n';
	}
	
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(arr, -1, sizeof(arr));
	memset(water, MAX, sizeof(water));

	cin >> R >> C;
	string in;
	for (int i = 0; i < R; i++) {
		cin >> in;
		for (int j = 0; j < C; j++) {
			if (in[j] == '.') {
				arr[i][j] = 0;
				water[i][j] = 0;
			}

			else if (in[j] == '*') {
				arr[i][j] = 1;
				water[i][j] = 1;
				waterSt.push({ i,j });//물 시작 지점 여러개
			}
			else if (in[j] == 'X') {
				arr[i][j] = 1;
				water[i][j] = 1;
			}
			else if (in[j] == 'D') {
				ed = { i,j };
				arr[i][j] = 0;
				water[i][j] = 1;
			}
			else if (in[j] == 'S') {
				st = { i,j };
				water[i][j] = 1;
				arr[i][j] = 0;
			}
		}
	}

	solve();
	return 0;

}