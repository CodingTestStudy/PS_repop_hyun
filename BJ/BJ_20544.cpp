//백준 20544 공룡게임 
#include <iostream>
#include <string.h>
using namespace std;

int N;
long long dp[1001][3][3][2];
long long mod = 1'000'000'007;

long long DP(int here, int hereHi, bool flag, int exHi) {

	long long& ret = dp[here][hereHi][exHi][flag];
	

	if (here == N - 1) {
		if (flag)return ret = 1;

		//한번도 2가 없는경우
		else return ret;
	}

	if (ret != 0)return ret;


	if (hereHi == 0) {
		ret += DP(here + 1, 0, flag, hereHi) % mod;
		ret += DP(here + 1, 1, flag, hereHi) % mod;
		ret += DP(here + 1, 2, true, hereHi) % mod;
	}
	else if (hereHi == 1) {
		if (exHi == 0) {
			ret += DP(here + 1, 0, flag, hereHi) % mod;
			ret += DP(here + 1, 1, flag, hereHi) % mod;
			ret += DP(here + 1, 2, true, hereHi) % mod;
		}
		else {
			//연속으로 3개 두지 못함
			ret += DP(here + 1, 0, flag, hereHi) % mod;

		}
	}
	else if (hereHi == 2) {
		if (exHi == 0) {
			ret += DP(here + 1, 0, flag, hereHi) % mod;
			ret += DP(here + 1, 1, flag, hereHi) % mod;
		}
		else {
			//연속으로 3개 두지 못함
			ret += DP(here + 1, 0, flag, hereHi) % mod;
		}
	}
	return ret = ret % mod;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	memset(dp, 0, sizeof(dp));
	

	cout << DP(0, 0, 0, 0) << '\n';
	return 0;

}