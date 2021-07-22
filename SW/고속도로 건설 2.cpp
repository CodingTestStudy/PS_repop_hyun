
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;
int N, M;

struct Edge {
	int from;
	int to;
	int weight;
};
int p[50000 + 1];
int ans;

bool comp(const Edge& a, const Edge& b) {

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


void solve(int test) {
	memset(p, -1, sizeof(p));
	vector<Edge> v;
	cin >> N >> M;
	int s, e, c;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> c;
		Edge a;
		a.from = s;
		a.to = e;
		a.weight = c;
		v.push_back(a);


	}

	sort(v.begin(), v.end(), comp);
	ans = 0;
	for (Edge& e : v) {
		if (find(e.from) == find(e.to))continue;
		else {
			merge(e.from, e.to);
			ans += e.weight;
		}
	}

	cout << "#" << test << " " << ans << '\n';
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solve(test_case);

	}

	return 0;
}




