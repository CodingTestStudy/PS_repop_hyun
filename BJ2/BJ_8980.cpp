#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef pair<int, pair<int, int>> P;
int capa[2001];
vector<P> v;
int N, C;
int M;
bool comp(P& a, P&b) {

	if (a.second.first == b.second.first) {
		return a.first < b.first;
	}
	else {
		return a.second.first < b.second.first;
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(capa, 0, sizeof(capa));
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int f, t, b;
		cin >> f >> t >> b;
		v.push_back({ f,{t,b} });
	
	}
	sort(v.begin(), v.end(), comp);

	int ans = 0;

	for (int i = 0; i < M; i++) {

		int maxBox = 0;
		for (int j = v[i].first; j < v[i].second.first; j++) {
			
			maxBox = max(maxBox, capa[j]);
		}
		
		int left = min(v[i].second.second, C - maxBox);
		ans += left;
		
		for (int j = v[i].first; j < v[i].second.first; j++) {
			
			capa[j] += left;
		}

	}

	cout << ans << '\n';

	return 0;

}
