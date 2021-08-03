#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;


typedef long long ll;
ll x, n;
vector<ll> arr;

int bin(int st, int ed, ll tar) {

	int lo = st;
	int hi = ed;
	int mid;
	while (lo <= hi) {
		mid = (hi + lo) / 2;

		if (arr[mid] == tar) {
			return mid;
		}
		else if (arr[mid] > tar) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}

	}

	return -1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> x) {
		cin >> n;
		x *= 10000000;
		arr.clear();
		for (int i = 0; i < n; i++) {
			ll a;
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
	
		bool flag = false;
		int eidx = -1;
		int i;
		for (i = 0; i < n - 1; i++) {
	
			eidx = bin(i + 1, n - 1, x - arr[i]);
			//찾음
			if (eidx != -1) {
				flag = true;
				break;
			}

		}

		if (!flag) {
			cout << "danger\n";
		}

		else {
			cout << "yes " << arr[i] << ' ' << arr[eidx] << '\n';

		}

	
	}

	return 0;

}