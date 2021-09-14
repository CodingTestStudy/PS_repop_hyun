#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
queue<P> airCon;
int N, M;
bool visited[4][2001][2001];
int arr[2001][2001];
P dir[4] = { {-1,0},{1,0},{0,-1},{0,1} }; //상하좌우
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, false, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				airCon.push({ i,j });
				visited[0][i][j] = 1;
				visited[1][i][j] = 1;
				visited[2][i][j] = 1;
				visited[3][i][j] = 1;
			}
		}
	}

	while (!airCon.empty()) {
		P con = airCon.front(); airCon.pop();
		
		for (int d = 0; d < 4; d++) {
			int n = d;
			int curY = con.first + dir[d].first;
			int curX = con.second + dir[d].second;
			while (0 <= curY && curY < N && 0 <= curX && curX < M) {
			

				if (visited[n][curY][curX])break; //이미 왔던곳이면 진행 안함
				visited[n][curY][curX] = true;
			


				if (arr[curY][curX] == 3) {
					if(n == 3 || n==1)n = (n + 1) % 4; //방향 바꿈
					else n = (n + 3) % 4;
				}
				else if (arr[curY][curX] == 4) {
					n = (n + 2) % 4;//방향 바꿈
				}
				else if (arr[curY][curX] == 1) {
					if (n == 2 || n == 3)break;//끝
				}
				else if (arr[curY][curX] == 2) {
					if (n == 0 || n == 1)break;
				}
					//이동
				curY = curY + dir[n].first;
				curX = curX + dir[n].second;
		

			}


			

		}

		
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bool flag = false;
			for (int k = 0; k < 4; k++) {
				if (!flag &&visited[k][i][j]) {
					flag = true;
					ans += 1;
				
				}
			}
		
		}
	}
	
	cout << ans << '\n';
	return 0;

}