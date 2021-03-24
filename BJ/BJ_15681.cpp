//백준 15681 트리와 쿼리 

//트리 dp
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N, R, Q;
int dp[100001];
vector<int> t[100001];
bool visited[100001];
int DFS(int cur) {
	visited[cur] = true;
	int &ret = dp[cur];
	
	for (int i = 0; i < t[cur].size(); i++) {
		
		int num = t[cur][i];
		if (!visited[num]) {
			ret += DFS(num);
		}

	}

	return ret;
}
void solve(int q) {


	cout << dp[q] << '\n';

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(visited, false, sizeof(visited));
	cin >> N >> R >> Q;
	fill(dp, dp + N, 1);
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		t[u-1].push_back(v-1);
		t[v-1].push_back(u-1);

	}

	DFS(R-1);
	int qq;
	for (int q = 0; q < Q; q++) {
		cin >> qq;
		solve(qq-1);
	}
	return 0;

}
