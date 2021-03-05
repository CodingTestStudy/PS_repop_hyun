//백준 11066 파일 합치기
#include <iostream>
#include <string.h>
using namespace std;
int dp[502][502];
int arr[502];
int sum[502];
int T, K;
const int INF = 987654321;
int merge(int a,int b) {

	if (a == b) {
		return 0;
	}
	
	if(a + 1 == b) {
		return dp[a][b] = arr[a] + arr[b];
	}

	int& ret = dp[a][b];
	if (ret != INF)return ret;

	for (int i = a; i < b; i++) {
		
		ret = min(merge(a,i) + merge(i + 1,b), ret);
	}

	return ret += sum[b]-sum[a-1];
}

void solve() {
	

	cout << merge(1, K) << '\n';


}
void set() {
	
	for (int i = 0; i <= K; i++) {
		fill(dp[i], dp[i] + K + 1, INF);
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sum[0] = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(arr, 0, sizeof(arr));
		cin >> K;
		set();
		for (int i = 1; i <= K; i++) {
		
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];

		}

		solve();

	}
	return 0;

}