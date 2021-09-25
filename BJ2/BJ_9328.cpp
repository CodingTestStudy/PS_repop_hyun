#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int T;
int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };
int h, w;
bool keys[30];
bool visited[105][105];
char arr[105][105];
string have = "";
int ans = 0;
queue <pair<int, int>> q;
vector<pair<int, int>> door[30]; //해당 문 위치
vector< pair<int, int>>st;

void init() {
	while (!q.empty())q.pop();
	have = "";
	ans = 0;
	memset(keys, 0, sizeof(keys));
	memset(visited, 0, sizeof(visited));
	st.clear();
	for (int i = 0; i < 30; i++) {
		door[i].clear();
	}


	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		string inn;
		cin >> inn;
		for (int j = 1; j <= w; j++) {
			arr[i][j] = inn[j-1];
			if ((i == 1 || i == h) || (j == 1 || j == w)) {
				if (arr[i][j] != '*')//벽과 문만 아니면 시작점 도달 가능성 계산에 넣음
				{
					st.push_back({ i,j });
				}

				//시작점 바닥, 문서,열쇠
				if (arr[i][j] == '.' || arr[i][j] == '$') { 
					visited[i][j] = 1;
					q.push({ i,j }); 
					
				}
				else if (97 <= arr[i][j] && arr[i][j] <= 122) {
					keys[arr[i][j] - 97] = 1;
					visited[i][j] = 1;
					q.push({ i,j });
				}
				else if (65 <= arr[i][j] && arr[i][j] <= 90) { //시작점의 문 
					door[arr[i][j] - 65].push_back({ i,j });
					q.push({ i,j });
				}
			}
			else if (65 <= arr[i][j] && arr[i][j] <= 90) { //문 위치 저장
				door[arr[i][j] - 65].push_back({ i,j });
				
			}
			
		}
	}
	
	cin >> have;
	if (have != "0") {
		for (int i = 0; i < have.length(); i++) {
			keys[have[i] - 97] = 1;
		}
	}


}

void solve() {
	init();

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		visited[curY][curX] = 1;
		if (arr[curY][curX] == '$')ans += 1;
		if (65 <= arr[curY][curX] && arr[curY][curX] <= 90) {
			if (!keys[arr[curY][curX] - 65]) { //문을 열수 있는 열쇠가 없다면
				continue;
			}
		}
	
		for (int i = 0; i < 4; i++) {
			int n_y = curY + yy[i];
			int n_x = curX + xx[i];
			
			if (1 <= n_y && n_y <= h && 1 <= n_x && n_x <= w) {
				if (!visited[n_y][n_x]) {
					char next = arr[n_y][n_x];
					if (next == '.' || next == '$') {
						visited[n_y][n_x] = 1;
						q.push({ n_y,n_x });
					}
					else if (97 <= next && next <= 122) { //열쇠
						keys[next - 97] = 1;
						if (!door[next - 97].empty()) { //열 수 있는 문
							for (pair<int, int>p : door[next - 97]) {
								
								if (visited[p.first][p.second]) { //해당 문이 도달가능한 위치일때만
									q.push({ p.first,p.second }); //문 위치부터 다시 BFS함
								}

							}
							door[next - 97].clear();
						}
						visited[n_y][n_x] = 1;
						q.push({ n_y,n_x });
					}
					else if (65 <= next && next <= 90) { //문 발견
						visited[n_y][n_x] = 1;
						if (keys[next - 65]) { //문을 열수 있는 열쇠가 있다면
							q.push({ n_y,n_x });
						}

					}
				

				}
			}


		}


	}


	cout << ans << '\n';


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		solve();
	}
	return 0;

}