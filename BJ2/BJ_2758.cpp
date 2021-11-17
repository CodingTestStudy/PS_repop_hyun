#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 10
#define MAXM 2000
using ll = unsigned long long;
int T;
int N, M;
ll dp[MAXN + 2][MAXM + 2];

ll func(int n, int m) {
	ll& ret = dp[n][m];
	if (ret != -1)return ret;

	if (m <= 0) {
		return 0;
	}


	ret = 0;

	ret += func(n - 1, m / 2);
	ret += func(n, m - 1);
	
	return ret;

}
void solve() {

	cin >> N >> M;
	ll ans = 0;


	cout << func(N, M) << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= MAXM; i++)dp[1][i] = i;
	cin >> T;
	while (T--)solve();
	return 0;

}