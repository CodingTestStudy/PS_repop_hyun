#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;

int V, E;

int dfsn[10001]; //dfs탐색 순서 번호
bool finished[10001];
int SN = 0; //SCC의 넘버링
int sn[10001];//sn[i] i가 속한 SCC의 번호
int cnt = 0;
vector<int>adj[10001];
stack<int> st;

vector<vector<int>>SCC;
int dfs(int cur) {

	dfsn[cur] = ++cnt; //현재 정점의 dfsn 설정
	st.push(cur);
	
	int ret = dfsn[cur];
	for (int next : adj[cur]) {
		if (dfsn[next] == 0)ret = min(ret, dfs(next));

		else if (!finished[next])ret = min(ret, dfsn[next]);
	}

	if (ret == dfsn[cur]) { // 자신이 제일 높은 정점일 경우 SCC추출
		vector<int> curScc;
		
		while (true) {
			int t = st.top();
			st.pop();
			curScc.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == cur) break; //본인 까지 넣으면 끝
		}

		sort(curScc.begin(), curScc.end());
		SCC.push_back(curScc);
		SN++;
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(finished, 0, sizeof(finished));
	memset(dfsn, 0, sizeof(dfsn));

	cin >> V >> E;
	int u, v;
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		
		adj[u-1].push_back(v-1);

	}

	for (int i = 0; i < V; i++) {
		if (dfsn[i] == 0)dfs(i);
	}
	
	sort(SCC.begin(), SCC.end());
	cout << SN << '\n';
	for (vector<int> sc : SCC) {
		for (int i = 0; i < sc.size(); i++) {
			cout << sc[i] + 1 << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;

}