#include <iostream>
#include <algorithm>

using namespace std;
int n, m;

const int INF = 987654321;
int dist[101][101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;

		}
	}


	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		dist[a - 1][b - 1] = min(dist[a-1][b-1],c);

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]); //i번 노드를 거쳐서 가는 수가 더 작은지 확인
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (dist[i][j] == INF)cout << 0 << ' ';

			else cout << dist[i][j] << ' ';
		}

		cout << '\n';
	}
	return 0;

}