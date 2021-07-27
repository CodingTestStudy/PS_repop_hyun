#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int N,P;
int arr[17][17];
int dp[17][1<<17];
int init = 0;
const int INF = 0x3f3f3f3f;
void hashing(string& s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == 'Y') {
			init = (init | (1<< i));
	
		}

	}
}

int bitCount(int a) {
	int cnt = 0;
	int n = a;
	while (n) {
		cnt += n & 1;
		n = n >> 1;
	}

	return cnt;
}

int func(int cur, int visited) {

	if (bitCount(visited) >= P) {
		return 0;

	}
	int& ret = dp[cur][visited];
	if (ret != INF)return ret;


	for (int i = 0; i < N; i++) {
		int next = 1 << i;
		if ((next & visited) == 0)
			for (int j = 0; j < N; j++) {
				if (((visited | next) & (1 << j))!= 0) { //켜져있는 것으로 부터 킴
					ret = min(ret, func(j, visited | next) + arr[cur][i]);
				}
			}

	}

	return ret;
}

 int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, INF, sizeof(dp));
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	
	}

	string inn;
	cin >> inn;
	hashing(inn);
	cin >> P;
	if (P == 0) {
		cout << 0 << '\n';
	}
	else {

		int ans = INF;
		for (int i = 0; i < N; i++) {
			if (inn[i] == 'Y') { //켜진 곳 부터 dfs시작
				ans = min(ans, func(i, init));
			}
		}
		if (ans == INF) {
			cout << -1 << '\n';
		}
		else cout << ans << '\n';


	}



	return 0;

}

