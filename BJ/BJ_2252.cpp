#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int N, M;
int indeg[32001];
vector<int> adj[32001];
queue<int>q;
vector<int> ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(indeg, 0, sizeof(indeg));
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		indeg[b-1]++; //indeg ++
	}
	for (int i = 0; i < N; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		
		int curr = q.front();
		ret.push_back(curr);
		q.pop();

		for (int n : adj[curr]) {
			
			indeg[n]--;
			if (indeg[n] == 0) {
				q.push(n);
			}
		}

	}


	for (int i = 0; i < ret.size(); i++) {

		cout << ret[i] + 1 << " ";
	}
	return 0;