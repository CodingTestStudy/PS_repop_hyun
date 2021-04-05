//백준 2470 두 용액
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const long long MAX = 0x3f3f3f3f3f3f3f3f;
int N;
typedef long long ll;
ll arr[100000 + 1];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int l = 0;
	int r = N - 1;
	ll ans = MAX;
	ll rAns = arr[l]; 
	ll lAns = arr[r];
	ll ret = rAns + lAns;
	while (l < r) {
		
		ret =arr[l] + arr[r];
		if (abs(ans) > abs(ret)) {
			ans = ret;
			rAns = arr[r];
			lAns = arr[l];
		}

		if (ret <= 0) {
			l += 1;
		}
		else r -= 1;
		
	}
	

	cout << lAns << " " << rAns << '\n';
	return 0;

}