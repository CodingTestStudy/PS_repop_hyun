#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
int parent[100000 + 1];
vector<int> adj[100000 + 1];
vector<int> t[100000 + 1];
void make_tree(int r, int p) {

	if (p != -1)t[p].push_back(r);

	for (int n : adj[r]) {
		if (n == p)continue;
		make_tree(n, r);
	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}

	make_tree(1,-1);


	for (int i = 1; i <= N; i++) {
		
		for (int c : t[i]) {
			parent[c] = i;
		}

	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
	return 0;

}
