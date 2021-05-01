
//백준 4195 virtual Friends

#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
int parent[1000001];
int setSize[1000001];

int findPar(int node) {

	if (parent[node] == node )return node;

	return parent[node] = findPar(parent[node]);
}

void merge(int a, int b) {
	a = findPar(a);
	b = findPar(b);

	if (a != b) {
		if (setSize[a] < setSize[b]) {
			swap(a, b);
		}

		parent[b] = a;
		setSize[a] += setSize[b];
		setSize[b] = 0;
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	int F;
	for (int t = 0; t < T; t++) {
		cin >> F;

		for (int i = 0; i < 1000001; i++) {
			parent[i] = i;
			setSize[i] = 1;
		}

		map<string, int> m;
		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
		
			//없으면 
			if (m.count(a) == 0) {
				m.insert({ a,m.size() + 1 });
			}
			if (m.count(b) == 0) {
				m.insert({ b,m.size() + 1 });
			}

			int aPar = findPar(m[a]);
			int bPar = findPar(m[b]);

			if (aPar == bPar) {
				cout << max(setSize[aPar], setSize[bPar]) << '\n';
			}
			else {
				merge(aPar, bPar);
				cout << max(setSize[aPar], setSize[bPar]) << '\n';
			}
		}
	}

	return 0;
}
