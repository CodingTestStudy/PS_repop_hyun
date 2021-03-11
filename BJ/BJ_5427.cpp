//백준 5427 FIRE
//시간복잡도 -> 1초 가능
#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
queue<pair<int,int>> EP;
queue<pair<int, int>> FP;
int fire[1002][1002];
int person[1002][1002];

int w, h;
pair<int, int> st;

int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };

void solve() {
	

	//fire
	
	while (!FP.empty()) {
		int y = FP.front().first;
		int x = FP.front().second;
		FP.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];
			if (0 <= n_y && n_y < h && 0 <= n_x && n_x < w) {
				if (fire[n_y][n_x] == 0) {
					fire[n_y][n_x] = fire[y][x] + 1;
					FP.push({ n_y,n_x });
				}
				
			}
		}
	}

	//person
	queue< pair<int, int> >q;
	q.push(st);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];

			if (0 <= n_y && n_y < h && 0 <= n_x && n_x < w) {
				if (person[n_y][n_x] == 0) {
					person[n_y][n_x] = person[y][x] + 1;
					q.push({ n_y,n_x });
				}
			}
		}
	}
	bool flag = false;
	int ret = 0x3f3f3f3f;
	while (!EP.empty()) {
		
		int y = EP.front().first;
		int x = EP.front().second;
		EP.pop();
		if (y == st.first && x == st.second) {
			ret = 0;
			flag = true;
		}
		if ((fire[y][x] - 1 > person[y][x] && person[y][x] > 0) || (fire[y][x] == 0 && person[y][x] > 0)) {
		
			flag = true;
			ret = min(ret, person[y][x]);
		}
	}

	if (!flag)cout << "IMPOSSIBLE\n";
	else cout << ret + 1<< '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string row;
		memset(fire, -1, sizeof(fire));
		memset(person, -1, sizeof(person));
		cin >> w >> h;
		
		for (int i = 0; i < h; i++) {
			cin >> row;
			for (int j = 0; j < w; j++) {

				if(row[j] == '.') {
					if (i == 0 || j == 0  || j == w - 1 || i == h - 1) {
						EP.push({ i,j });
					}
					person[i][j] = 0;
					fire[i][j] = 0;
				}

				else if(row[j] == '#') {
					continue;
				}

				else if (row[j] == '*') {
					FP.push({ i,j });
					fire[i][j] = 1;
					person[i][j] = -1;
				}

				else if (row[j] == '@') {
					
					st = { i,j };
					if (i == 0 || j == 0 || j == w - 1 || i == h - 1) {
						EP.push({ i,j });
					}
					person[i][j] = 0;
					fire[i][j] = 0;
				}
			}
			
		}

		solve();
	
	}
	return 0;

}