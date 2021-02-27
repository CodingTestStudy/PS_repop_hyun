//백준 1516 게임개발
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int indegree[501];
vector<int> adj[501];
int Time[501];
int ret[501];
int ans[501];
void timeCal() {
	
	for (int i = 0; i < N; i++) {
		int cur = ret[i];
		
		for (int next : adj[cur]) {
			
			ans[next] = max(ans[next], ans[cur] + Time[next]);
		}
	}
}
void print() {

	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}
}
void solve() {

	queue<int> q;

	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0)q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int cur = q.front();
		q.pop();
		ret[i] = cur;
		
		for (int next : adj[cur]) {
			if (--indegree[next] == 0)q.push(next);

		}
	}

	
	timeCal();

	print();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(indegree, 0, sizeof(indegree));
	
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		Time[i] = time;
		ans[i] = time;
		while (1) {
			cin >> input;
			if (input == -1)break;
			adj[input-1].push_back(i);
			++indegree[i];
		}

		
	}
	

	solve();
	return 0;

}
