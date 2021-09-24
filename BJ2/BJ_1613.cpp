#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int n, k;
int s;
const int INF = 0x3f3f3f3f;
int arr[402][402];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	memset(arr, INF, sizeof(arr));

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {
			
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}



	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;

		if (arr[a][b] == INF && arr[b][a] == INF) {
			cout << 0 << '\n';
			

		}
		else {
			if (arr[b][a] != INF && arr[a][b] == INF) {
				cout << -1 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		
	}
	return 0;

}