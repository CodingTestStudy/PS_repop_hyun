//백준 14502번 연구소
#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int arr[10][10];
int map[10][10];
int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };
int ans;
struct coor {

	int Y;
	int X;

};
typedef struct coor coor;
vector<coor> C;
vector<int> idx;
int simula(coor a,coor b , coor c) {
	int ret = 0;

	queue<coor> q;
	//초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			map[i][j] = arr[i][j];
			if (map[i][j] == 2) {
				coor tmp;
				tmp.Y = i;
				tmp.X = j;
				q.push(tmp);
			}

		}
	}
	map[a.Y][a.X] = 1;
	map[b.Y][b.X] = 1;
	map[c.Y][c.X] = 1;

	while (!q.empty()) {
		int y = q.front().Y;
		int x = q.front().X;
		map[y][x] = 2;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];

			if (0 <= n_y && n_y < N && 0 <= n_x && n_x < M) {
				if (map[n_y][n_x] == 0) {
					coor tmp;
					tmp.Y = n_y;
					tmp.X = n_x;
			
					q.push(tmp);
				}
			}
		}


	}
	
	//counting
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(map[i][j]==0){
				ret += 1;
			}

		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			cin >> arr[i][j];

			if (arr[i][j] == 0) {
			
				coor inn;
				inn.X = j;
				inn.Y = i;
				C.push_back(inn);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		idx.push_back(1);
	}
	for (int i = 0; i < C.size() - 3; i++) {
		idx.push_back(0);
	}

	sort(idx.begin(), idx.end()); 

	do {
		vector<coor> tmp;
		for (int i = 0; i < idx.size(); i++) {

			if (idx[i] == 1) {
				tmp.push_back(C[i]);
			}
		}

		ans = max(ans,simula(tmp[0], tmp[1], tmp[2]));

	} while (next_permutation(idx.begin(), idx.end()));


	cout << ans << '\n';
	return 0;

}
