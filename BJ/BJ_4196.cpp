//백준 4196 도미노 SCC 연습
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
int T;
int N, M;
int ans;
int sn;
vector<int> d[100001];
bool finished[100001];
int SccNum[100001];
stack<int> s;
int dfsn[100001];
int cnt;
int DFS(int cur) {

	//방문 번호 매김
	dfsn[cur] = ++cnt;
	s.push(cur);
	int ret = dfsn[cur];
	for (int i = 0; i < d[cur].size(); i++) {
		int next = d[cur][i];
		if (dfsn[next] == 0)ret = min(ret, DFS(next));

		else if (!finished[next])ret = min(ret, dfsn[next]);
	}
	
	// SCC 탐색완료
	if (ret == dfsn[cur]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			SccNum[t] = sn;
			if (t == cur)break;
		}
		sn++;
	}

	return ret;
}
void solve() {
	ans = 0;
	cnt = 0;
	sn = 0;
	for (int i = 0; i < N; i++) {
		if (dfsn[i] == 0)DFS(i);
	}

	int degree[100001] = { 0 };
	
	for (int i = 0; i < N; i++) {
		// i -> j 간선
		for (int j : d[i]) {
			if (SccNum[i] != SccNum[j]) {

				degree[SccNum[j]]++;
			}
		}
	}


	for (int i = 0; i < sn; i++) {
		if (degree[i] == 0)ans += 1;
	}

	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		memset(finished, 0, sizeof(finished));
		memset(dfsn, 0, sizeof(dfsn));
		memset(SccNum, 0, sizeof(SccNum));
		int a, b; //a to b
		for (int i = 0; i < N; i++) {
			d[i].clear();
		}

		for (int i = 0; i < M; i++) {

			cin >> a >> b;
			d[a - 1].push_back(b - 1);

		}

		solve();


	}
	return 0;

}