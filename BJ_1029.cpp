#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int arr[16][16];
int dp[16][1 << 14];
int dfs(int cur,int visited,int ex) {

	//모두를 거쳐서 갈곳이 없는 경우
	if (visited == ((1 << N) - 1)) {
		return 1;
	}

	int& ret = dp[cur][visited];
	if (ret != -1)return ret;

	bool flag = false;
	for (int i = 0; i < N; i++) {
		
		if (arr[cur][i] >= ex) { //더 비싸게 팔아야함
			if (!(visited & (1 << i))) {
				flag = true;
				int v = visited | (1 << i);
				ret = max(ret, dfs(i, v, arr[cur][i]));
			}
		}
	}

	if (flag) { //더 갈 곳이 있었던 경우
		return ret + 1;
	}
	else return 1; //더 이상 갈 곳이 없는 경우
}
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			
			arr[i][j] = input[j];
		}
	}


	cout << dfs(0, 1, 0) << '\n';
	return 0;
}