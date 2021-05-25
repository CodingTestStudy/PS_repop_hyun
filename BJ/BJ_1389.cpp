#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
int N, M;

using namespace std;
const int INF = 0x3f3f3f3f;
int adj[101][101];


bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first)return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(adj, INF, sizeof(adj));

	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		adj[i][i] = 0;
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;

	}


	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];

				}
			}
		}
	}

	vector<pair<int, int>> ans;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;

			else {
				sum += adj[i][j];
			}
		}

		ans.push_back({ sum,i });

	}
	
	sort(ans.begin(), ans.end(),comp);
	
	
	cout << ans.begin()->second << '\n';

	return 0;

}