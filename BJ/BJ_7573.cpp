//백준 7573 고기잡이
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int N, I, M;
int ret = 0;
vector<pair<int, int>> v;


void check(int y, int x,int toY, int toX) {
	//그물이 범위넘어가면 안셈
	if (N < y + toY || N < x + toX ) {
		ret = max(ret, 1);
		return;
	}

	int cnt = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (y <= v[i].first && v[i].first <=y + toY && x <= v[i].second &&  v[i].second <= x+ toX) {
			++cnt;
		}

	}
	
	ret = max(ret, cnt);

}
void solve() {
	
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			for (int k = 1; k < I / 2; k++) {

				check(v[i].first, v[j].second, k, (I / 2) - k);
			}
		}
	}

	cout << ret << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> I >> M;
	int y, x;
	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		v.push_back({ y ,x });
	}

	solve();

	return 0;

}