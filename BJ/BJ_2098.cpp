#include <iostream>
#include <algorithm>
#include <string.h>
int arr[17][17];
int dp[17][1 << 16];
int N;
using namespace std;

#define INF 987654321

int dfs(int cur , int visited) {

	if (dp[cur][visited] != -1)return dp[cur][visited];



	//base case
	if (visited == (1 << N) - 1) {
		if (arr[cur][0] != 0) return arr[cur][0];//돌아갈 수 있어야됨
		else return INF;
	}
	
	dp[cur][visited] = INF;

	for (int i = 0; i < N; i++) {

		if (arr[cur][i] != 0) {
			if (!((1 << i) & visited)) { //안가본 곳이라면
				int v = visited | (1 << i);
				dp[cur][visited] = min(dp[cur][visited], arr[cur][i] + dfs(i, v));
			}
		}
		
	}


	return dp[cur][visited];
}
int main() {
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			
			cin >> arr[i][j];
			
		}

	}

	//첫번째 노드부터 시작
	cout << dfs(0,1) << '\n';

	return 0;
}