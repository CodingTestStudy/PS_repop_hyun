#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N,S;
vector<int> Lsum;
vector<int> Rsum;
int arr[41];
long long ans = 0;

void leftSum(int idx, int sum) {
	if (idx == N / 2) {
		Lsum.push_back(sum);
		return;
	}
	leftSum(idx + 1, sum + arr[idx]);
	leftSum(idx + 1, sum);

}

void rightSum(int idx, int sum) {
	if (idx == N) {
		Rsum.push_back(sum);
		return;
	}
	rightSum(idx + 1, sum + arr[idx]);
	rightSum(idx + 1, sum);

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	leftSum(0, 0);
	rightSum(N / 2 , 0);

	sort(Rsum.begin(), Rsum.end());
	
	for (int i = 0; i < Lsum.size(); i++) {
		auto u = upper_bound(Rsum.begin(), Rsum.end(), S - Lsum[i]);
		auto l = lower_bound(Rsum.begin(), Rsum.end(), S - Lsum[i]);
		if (u != l) {
			ans += u - l;
			
		}
	}
		
	

	if (S == 0)ans -= 1;

	cout << ans << '\n';
	return 0;

}