#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
using ll = long long;
int N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<ll> arr;
	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	ll ret = 0x3f3f3f3f3f3f3f3f;
	ll x, y, z;
	for (int i = 0; i < N - 2; i++) {

		int lo = i + 1;
		int hi = N - 1;
		
		while (lo < hi) {
			ll sum = arr[i] + arr[lo] +arr[hi];
			if (abs(sum) < abs(ret)) {
				ret = abs(sum);
				x = arr[i];
				y = arr[lo];
				z = arr[hi];
			}
			
			if (sum < 0)lo++;
			else hi--;
		}
	


	}

	cout << x << " " << y << " " << z << '\n';

	return 0;

}