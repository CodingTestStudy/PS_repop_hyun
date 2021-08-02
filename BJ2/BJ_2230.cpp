#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
const int INF = 0x3f3f3f3f;
int arr[100001];
int N, M;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int ans = INF;
	int lo = 0;
	int hi = 0;
	while (hi < N) {
		int ret = abs(arr[hi] - arr[lo]);
		if (ret < M) {
			hi += 1;
		}
		else if (ret > M) {
			ans = min(ans, ret);
			lo += 1;
		}
		else if (ret == M) {
			ans = M;
			break;
		}
	}

	cout << ans << '\n';
	return 0;

}