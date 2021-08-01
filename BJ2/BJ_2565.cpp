#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int dp[501];
int arr[501];
int N;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });

	}

	sort(v.begin(), v.end());


	for (int i = 0; i < v.size(); i++) {
		arr[i] = v[i].second;
		dp[i] = 1;

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);

	}

	cout << N-ans << '\n';
	return 0;

}

