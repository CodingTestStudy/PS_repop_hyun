#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 50
int N;
vector<int>adj[MAXN + 1];
int ans[MAXN + 1];
const int INF = 0x3f3f3f3f;
int minS = INF;
int daik(int start) {
	int dist[MAXN + 1];
	memset(dist, INF, sizeof(dist));
	queue<int>q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}


	}
	int m=-1;
	for (int i = 1; i <= N; i++) {
		if (start == i)continue;
		m = max(m, dist[i]);
	}
	
	return m;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while(1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)break;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
	
		ans[i]=daik(i);
		minS = min(minS, ans[i]);

	}

	vector<int> ret;
	for (int i = 1; i <= N; i++) {
		if (minS == ans[i]) {
			ret.push_back(i);
		}
	}



	sort(ret.begin(), ret.end());
	
	cout << minS << " " << ret.size() << '\n';
	for (int s : ret) {
		cout << s << " ";
	}
	cout << '\n';
	return 0;

}
