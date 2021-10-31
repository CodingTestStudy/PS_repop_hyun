#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
#define NMAX 50000
using ll = long long;
using P = pair<ll, ll>;
ll N, maxG, curG, D;
vector<P> v;
stack<int> s;
int nextSmall[NMAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> maxG >> curG >> D;
	for (int i = 0; i < N; i++) {
		ll x, c;
		cin >> x >> c;
		v.push_back({ x,c });

	}
	sort(v.begin(), v.end());
	//다음으로 가장 싼 주유소 찾기
	for (int i = N - 1; i >= 0; i--) {
		while (s.size() > 0 && v[s.top()].second >= v[i].second) {
			s.pop();
		}
		nextSmall[i] = (s.size() == 0 ? -1 : s.top());
		s.push(i);

	}

	curG -= v[0].first;
	ll cost = 0;
	for (int i = 0; i < N; i++) {

		if (curG < 0) {
			cout << -1 << '\n';
			return 0;
		}

		ll need = min(maxG, (nextSmall[i] == -1 ? D : v[nextSmall[i]].first) - v[i].first);
		if (need > curG) {
			cost += (need - curG) * v[i].second;
			curG = need;
		}

		curG -= (i == N - 1 ? D : v[i + 1].first) - v[i].first;

	}
	if (curG < 0) {
		cout << -1 << '\n';
		return 0;

	}
	else cout << cost << '\n';
	return 0;

}