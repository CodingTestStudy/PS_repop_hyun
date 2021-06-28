//백준 1647번

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int cost;
	int v1;
	int v2;
};
typedef struct Edge Edge;
int p[100000 + 1];
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
bool comp(Edge& a, Edge& b) {
	return a.cost < b.cost;

}

int N, M;
bool vertex[100000 + 1];
vector<Edge> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(p, -1, sizeof(p)); 
	memset(vertex, false, sizeof(vertex));
	cin >> N >> M;
	int a, b, c;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		Edge e;
		e.cost = c;
		e.v1 = a;
		e.v2 = b;
		v.push_back(e);
	}
	sort(v.begin(), v.end(), comp);

	int ans = 0;
	int idx = 0;
	int ee = 0;
	for ( ; idx < v.size(); idx++) {
		if (ee == N - 1)break;
		int V1 = v[idx].v1;
		int V2 = v[idx].v2;
		if (find(V1) == find(V2))continue;
		merge(V1, V2);
		ee += 1;
		ans += v[idx].cost;

	}
	ans -= v[idx - 1].cost;

	cout << ans << '\n';

	
	return 0;

}

