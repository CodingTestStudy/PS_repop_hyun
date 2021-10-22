
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cassert>
using namespace std;
int N;
vector<int>arr;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	long long ans = 0;
	for (int i = 0; i < N-2; i++) {

		for (int j = i + 1; j < N - 1; j++) {
			int val = -(arr[i] + arr[j]);
			int lo = lower_bound(arr.begin()+j + 1, arr.end(), val)- arr.begin();
			if (lo == N || arr[lo] != val)continue;
			int hi = upper_bound(arr.begin() + j + 1, arr.end(), val) - arr.begin();
	
			ans += hi - lo;
		}

	}

	cout << ans << '\n';
	return 0;

}