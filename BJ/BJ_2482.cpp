//백준 2482 색상환
#include <iostream>
#include <string.h>
using namespace std;
int dp[1001][1001];

int DP(int n,int k) {

	if (n / 2 < k)return 0;
	if (k == 1)return n;

	int& ret = dp[n][k];
	if (ret != -1)return ret;

	return ret = (DP(n-2,k-1) + DP(n-1,k)) % 1000000003;

}
int main() {

	memset(dp, -1, sizeof(dp));
	
	int N;
	int K;
	cin >> N >> K;

	
	cout << DP(N, K) << '\n';
	

	return 0;

}