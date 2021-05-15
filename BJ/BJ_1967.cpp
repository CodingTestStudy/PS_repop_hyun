#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

vector<P> adj[10001];
int n;
int ans = 0;

int DFS(int cur,int cc) { //가장 깊은 값 반환

	if (adj[cur].empty()) {
		return cc;
	}
	else {

		vector<int>list; //가장 깊은값들 저장리스트 정답구하기용
		int depth = 0;
		for (int i = 0; i < adj[cur].size(); i++) {
			int cal = DFS(adj[cur][i].first, adj[cur][i].second);
			depth = max(depth,cal);
			list.push_back(cal);
		}
		//정답구하기
		if (list.size() > 1) {
			sort(list.begin(), list.end(),greater<int>());
			ans = max(ans, list[0] + list[1]);

		}

		return depth+cc;
	}
	

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int from, to, cost;
	for (int i = 0; i < n - 1; i++) {

		cin >> from >> to >> cost;
		adj[from-1].push_back({ to-1,cost });

	}

	
	ans = max(ans,DFS(0,0));

	cout << ans << '\n';
	return 0;

}