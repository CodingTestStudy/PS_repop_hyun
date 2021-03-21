//백준 9663 N-Queen
#include <iostream>
#include <string.h>
using namespace std;
int N;
//상 대각 시계방향부터,
int y[3] = {-1, -1,-1};
int x[3] = {0, -1,1};
int ret = 0;
bool arr[15][15];

bool isOk(int cnt , int i) {

	for (int j = 0; j < 3; j++) {
		int n_r = cnt + y[j];
		int n_c = i + x[j];
		while (0 <= n_r && n_r < N && 0 <= n_c && n_c < N) {

			if (arr[n_r][n_c] == true)return false;

			n_r = n_r + y[j];
			n_c = n_c + x[j];
		}
	}

	return true;
}
void DFS(int cnt) {
	if (cnt == N) {
		ret++;
		return;
	}

	else {

		for (int i = 0; i < N; i++) {
			if (!arr[cnt][i] && isOk(cnt,i)) {
				
				arr[cnt][i] = true;
				DFS(cnt + 1);
				arr[cnt][i] = false;
			}
		}

	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(arr, false, sizeof(arr));
	cin >> N;
	
	DFS(0);

	cout << ret << '\n';
	return 0;

}	