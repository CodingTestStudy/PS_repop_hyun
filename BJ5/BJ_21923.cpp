#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
using ll = long long;
#define MAX 1000
ll arr[MAX + 1][MAX + 1];
ll u[MAX + 1][MAX + 1];
ll d[MAX + 1][MAX + 1];
int N, M;
ll ans;
const ll INF = -0x3f3f3f3f3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			
		}
	}

	u[N][1] = arr[N][1];
	d[N][M] = arr[N][M];

	for (int i = N; i >= 0; i--) {
		for (int j = 1; j <= M; j++) {
			
			if (i == N && j == 1)continue;
			//좌 x
			if (j == 1 && i != N) {
				u[i][j] = u[i+1][j] + arr[i][j];
			}
			//아래 x
			else if (i == N && j != 1) {
				u[i][j] = u[i][j - 1] + arr[i][j];
			}
			
			else {
				u[i][j] = max(u[i + 1][j], u[i][j - 1]) + arr[i][j];

			}
		
		}
	}



	for (int i = N; i >= 1; i--) {
		for (int j = M; j >= 1; j--) {

			if (i == N && j == M)continue;
			//아래 x
			if (i == N && j != M) {
				d[i][j] = d[i][j+1] + arr[i][j];
			}
			//우 x
			else if (j == M && i != N) {
				d[i][j] =d[i+1][j] + arr[i][j];
			}

			else {
				d[i][j] = max(d[i + 1][j], d[i][j + 1]) + arr[i][j];

			}

		}
	}
	
	ans = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			ans = max(ans, u[i][j] + d[i][j]);
		}
	}

	cout << ans << '\n';
	return 0;

}
