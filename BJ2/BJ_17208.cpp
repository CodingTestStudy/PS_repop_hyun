#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int dp[101][301][301];
int N, M, K;
int cheese[301];
int fri[301];

int func(int num , int ch, int fr) {
	if (num == N)return 0;
	int& ret = dp[num][ch][fr];
	if (ret != -1)return ret;


	ret = 0;
	if (ch >= cheese[num] && fr >= fri[num]) {
		ret = func(num + 1, ch - cheese[num], fr - fri[num]) + 1;
	}
	ret = max(ret, func(num + 1, ch, fr));

	return ret;
	

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {

		cin >> cheese[i] >> fri[i];

	}




	cout << func(0, M, K) << '\n';
	return 0;

}