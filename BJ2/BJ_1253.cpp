#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
int N;
vector<ll> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		arr.push_back(x);

	}

	sort(arr.begin(), arr.end());
	int ans = 0;

	for (int i = 0; i < arr.size(); i++) {
		ll tar = arr[i];
		int l = 0; int r = N - 1;
		while (l < r) {
			ll sum = arr[l] + arr[r];

			if (sum < tar)l++;
			else if (sum > tar)r--;
			else if (sum == tar) {
				if (l == i)l++;
				else if (r == i)r--;

				else {
					ans += 1;
					break;
				}
			}
		}

	}
	

	cout << ans << '\n';
	return 0;

}