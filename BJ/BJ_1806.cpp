#include <iostream>
using namespace std;
int N, S;
int arr[100000 + 1];

const int INF = 0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int lo = 0;
	int hi = 0;
	int sum = arr[0];
	int ans = INF;
	while(lo <= hi && hi < N) {
		
		if (sum < S) {
			sum += arr[++hi];

		}
		else if (sum > S) {
			ans = (ans <= hi - lo + 1) ? ans : hi - lo + 1;
			sum -= arr[lo++];

		}
		else if (sum == S) {
			ans = (ans <= hi - lo + 1) ? ans : hi - lo + 1;
			sum += arr[++hi];

		}
	}

	if (ans == INF)cout << 0 << '\n';
	else cout << ans << '\n';
	
	return 0;

}