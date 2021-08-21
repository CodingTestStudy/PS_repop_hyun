#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define int unsigned long long
int S;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> S;
	int hi = S;
	int lo = 1;

	while (lo < hi) {
		int mid = (hi + lo) / 2;
		
		if ((mid * (mid + 1)) / 2 > S) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
		
	}



	if (lo-1 == 0)cout << 1 << '\n';
	else cout << lo-1<< '\n';
	return 0;

}