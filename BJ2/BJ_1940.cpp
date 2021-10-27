#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
int M;
int arr[15000 + 2];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	int ans = 0;

	
	int lo = 0;
	int hi = N - 1;

	while (lo < hi) {
		int sum = arr[lo] + arr[hi];

		if (sum == M) {
			ans++;
		}

		if (sum <= M) {
			lo++;
		}
		else if (sum > M)hi--;
	}


	cout << ans << '\n';
	return 0;

}