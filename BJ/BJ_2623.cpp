//백준 2623 음악프로그램
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;

bool visited[1001] = { false };
vector<vector<int>>adj;
vector<int> ret;

void DFS(int here) {

	visited[here] = true;

	for (int i = 0; i < N; i++) {
		if (adj[here][i] && !visited[i])DFS(i);
	}

	ret.push_back(here);

}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	adj = vector<vector<int>>(1001, vector<int>(1001, 0));
	cin >> N >> M;
	int num;
	int u,v;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cin >> u; //맨 처음 순서 
		
		for (int j = 0; j < num - 1; j++) {
			cin >> v;
			adj[u-1][v-1] = 1; // 연결
			u = v;
		}
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i])DFS(i);

	}

	reverse(ret.begin(), ret.end());

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (adj[ret[j]][ret[i]]) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}


	for (int path : ret) {
		cout << path + 1<< '\n';
	}
	return 0;

}
