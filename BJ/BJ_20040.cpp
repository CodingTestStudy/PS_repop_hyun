#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;
int n, m;
int p[500000 + 1];
vector<pair<int, int>>v;
int find(int a) {
	if (p[a] < 0)return a;
	p[a] = find(p[a]);
	return p[a];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(p, -1, sizeof(p));
	bool isEnd = false;
	cin >> n >> m;
	int a, b;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
		
	}
	int idx = 0;
	for (idx = 0; idx < v.size(); idx++) {
		a = v[idx].first;
		b = v[idx].second;

		if (find(a) == find(b)) {
			isEnd = true;
			break;
		}
		else {
			merge(a, b);
		}

	}

	if (isEnd)cout << idx + 1 << '\n';
	else cout << 0 << '\n';
	return 0;

}