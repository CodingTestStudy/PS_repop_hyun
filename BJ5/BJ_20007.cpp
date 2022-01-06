#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 1000
int adj[MAXN + 1][MAXN + 1];
int N, M, X, Y;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X >> Y;
	memset(adj, INF, sizeof(adj));
	for (int i = 0; i < N; i++) {
		adj[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;

		
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	
	


	vector<int> v;

	for (int i = 0; i < N; i++) {
		v.emplace_back(adj[Y][i]*2);
	}
	
	sort(v.begin(), v.end());
	int ans = 0;
	int x = X;
	bool flag = 0;
	for (int e : v) {
		if (x < e) {
			ans++;
			x = X;
			
			//다음날 가도 안되면 -1
			if (x < e){
				flag = 1;
				break;
			}
			else {
				x -= e;
			}
			
		}
		else {
			x -= e;
		}

	}
	
	if (flag)cout << -1 << '\n';
	else cout << ans+1 << '\n';

	return 0;

}