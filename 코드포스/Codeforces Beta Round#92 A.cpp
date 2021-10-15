#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int n, a, b;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> a >> b;
	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int f = i - 1;
		int e = n - i;

		if (f >= a && e <= b) {
			ans++;
		}


	}

	cout << ans << '\n';

	return 0;

}