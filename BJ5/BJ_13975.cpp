#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
#define MAXN 1000000
int T;
int N;

void solve() {
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		pq.push(x);
	}
	ll ans = 0;
	while (pq.size() > 1) {
		ll f = pq.top(); pq.pop();
		ll s = pq.top(); pq.pop();

		ll new_num = f + s;
		ans += new_num;
		pq.push(new_num);

	}



	cout << ans << '\n';

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--)solve();
	return 0;

}
