#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
#define MAXN 880
#define range(r,c,n_y,n_x) 0<= n_y && n_y < r && 0<= n_x && n_x < c

int yy[4] = { -1,1,-1,1 };
int xx[4] = { 1,1,-1,-1 };

int R, C;

int D1[MAXN + 1][MAXN + 1]; // 북서
int D2[MAXN + 1][MAXN + 1]; // 남서
int D3[MAXN + 1][MAXN + 1]; // 북동
int D4[MAXN + 1][MAXN + 1]; // 남동
string inn;
int arr[MAXN + 1][MAXN + 1];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> inn;
		for (int j = 0; j < C; j++) {
			arr[i][j] = inn[j] - '0';
		}
	}
	memset(D1, 0, sizeof(D1));
	memset(D2, 0, sizeof(D2));
	memset(D3, 0, sizeof(D3));
	memset(D4, 0, sizeof(D4));



	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (arr[i][j] == 1) {
				
				D1[i][j] = D1[i - 1][j +1] + 1;
				D3[i][j] = D3[i - 1][j - 1] + 1;

				
			}
		}

	}


	for (int i = R-1; i >=0; i--) {
		for (int j = 0; j < C; j++) {

			if (arr[i][j] == 1) {

				D2[i][j] = D2[i + 1][j + 1] + 1;
				D4[i][j] = D4[i + 1][j - 1] + 1;


			}
		}

	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			int size = min(D1[i][j], D2[i][j]);

			if (size < ans)continue;

			for (int sz = size; sz >= 1; sz--) {
				if (j + 2 * sz - 2 >= C)continue;
				if (sz < ans)break;
				if (sz <= min(D3[i][j + 2 * sz - 2], D4[i][j + 2 * sz - 2])) {
					ans = max(ans, sz);
				}

			}


		}
	}

	cout << ans << '\n';
	return 0;

}