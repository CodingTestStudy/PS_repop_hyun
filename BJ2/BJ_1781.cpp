#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> P;

ll N;

priority_queue<ll> pq;
vector<P> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int dead, cup;
		cin >> dead >> cup;
		v.push_back({ dead-1,cup });
		

	}

	ll ans = 0;

	sort(v.begin(), v.end());

	int day = N - 1;
	priority_queue<int>pq;
	for (int i = N - 1; i >= 0; i--) {

		while ((day >= 0) && (v[day].first == i )) {
			pq.push(v[day].second);
			day--;
			
		}


		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}




	cout << ans << '\n';
	return 0;

}