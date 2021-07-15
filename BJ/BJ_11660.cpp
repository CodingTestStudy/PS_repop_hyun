#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX_N 1024
using namespace std;

int N, M;

int arr[MAX_N + 1][MAX_N + 1];
int sumArr[MAX_N + 1][MAX_N + 1] = { 0 };
void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sumArr[i][j] = arr[i][j] + sumArr[i][j-1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sumArr[j][i] +=  sumArr[j-1][i];
		}
	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			
		}
	}
	init();

	int a, b, c, d;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		
		
		ans = sumArr[c][d] - sumArr[a - 1][d] - sumArr[c][b - 1] + sumArr[a - 1][b - 1];

		cout << ans << '\n';

	}


	return 0;

}
