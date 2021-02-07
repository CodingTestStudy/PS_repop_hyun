//백준 11403 경로찾기
#include <iostream>
using namespace std;

int adj[101][101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;

}