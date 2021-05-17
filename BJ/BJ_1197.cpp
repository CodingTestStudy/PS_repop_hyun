#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;
struct Edge {
	int from;
	int to;
	int weight;
};
int V, E;
vector<Edge> v;

int p[10000 + 1];

bool comp(Edge& a, Edge& b) {

	return a.weight < b.weight;

}

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


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(p, -1, sizeof(p));
	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		Edge e;
		e.from = a;
		e.to = b;
		e.weight = c;
		v.push_back(e);
	}

	sort(v.begin(), v.end(), comp);
	int ans = 0;
	for (Edge &e : v) {
		if (find(e.from) == find(e.to))continue;
		else {
			merge(e.from, e.to);
			ans += e.weight;
		}
	}
	cout << ans << '\n';
	return 0;

}