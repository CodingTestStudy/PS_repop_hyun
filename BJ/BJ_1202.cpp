#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, K;
typedef long long int ll;
priority_queue<pair<ll, ll>> pq;
vector<pair<ll, ll>> J;
vector<ll> bag;
ll ans = 0;
vector<pair<ll, ll>>::iterator it;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	int w, v;
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		J.push_back({ w,v });
	}
	int b;
	for (int i = 0; i < K; i++) {
		cin >> b;
		bag.push_back(b);
		

	}
	sort(J.begin(), J.end());
	sort(bag.begin(), bag.end());
	
	it = J.begin();
	
	for (int i = 0; i < K; i++) {

		int BagWeight = bag[i];
	
		while (it != J.end() && it->first <= BagWeight) {
			
			pq.push({ it->second,it->first });

			it += 1;

		}
		

		if (!pq.empty()) {
			ans += pq.top().first;
			pq.pop();
		}


	}

	cout << ans << '\n';
	return 0;

}