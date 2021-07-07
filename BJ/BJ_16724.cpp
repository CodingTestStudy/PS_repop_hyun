#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int N, M;
char input[1001][1001];
int p[1000000 + 1];
bool visited[1001][1001];
int find(int a) {
	if (p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];

}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a; // a가 부모
}

void DFS(int y,int x) {


	visited[y][x] = true;
	switch (input[y][x]) {
		case 'D': {
			merge(y * M + x, (y + 1) * M + x);
			if (!visited[y+1][x]) {
				DFS(y + 1, x);
			}

			break;
		}
		case 'U': {
			merge(y * M + x, (y - 1) * M + x);
			if (!visited[y - 1][x]) {
				DFS(y -1 , x);
			}
		
			break;
		}
		case 'R': {
			merge(y * M + x, y * M + (x + 1));
			if (!visited[y][x+1]) {
				DFS(y , x+1);
			}
			break;
		}
		case 'L': {
			merge(y * M + x, y * M + (x - 1));
			if (!visited[y][x - 1]) {
				DFS(y, x - 1);
			}
	
			break;
		}
		
	}

}
void solve() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
			}
		}
	}

	int ans = 0;
	int cnt[1000000 + 1] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt[find(i * M + j)]++;
		}
	}
	for (int i = 0; i < N * M; i++) {
		if (cnt[i] > 0) ans++;
	}
	cout << ans << '\n';

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	string a;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int j = 0; j < M; j++) {
			input[i][j] = a[j];
		}
	}
	memset(visited, false, sizeof(visited));
	solve();

	return 0;

}

