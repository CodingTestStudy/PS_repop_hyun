#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = unsigned long long;
int T;
ll n;

void solve() {
	cin >> n;
	vector<ll> arr;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sum += x;
		arr.push_back(x);
		
	}

	if ((2 * sum) % n != 0) {
		cout << 0 << '\n';
		return;
	}
	ll find = (2 * sum) / n;
	ll cnt = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {

		ll p = find - arr[i];
		ll u = upper_bound(arr.begin()+i+1, arr.end(), p) - arr.begin();
		ll l = lower_bound(arr.begin()+i+1, arr.end(), p) - arr.begin();

		cnt += u - l;


	}

	cout << cnt << '\n';
	return;
	

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++) {

		solve();
	}
	return 0;

}

