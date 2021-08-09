#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;
int N, M;

int gcd(int a, int b) {

	if (a < b)swap(a, b);
	if (b == 0|| b == 1)return a;

	return gcd(b, a % b);
}
int arr[101];
int v[101];
vector<int>ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < N - 1; i++) {
		v[i] = abs(arr[i + 1] - arr[i]);
	}
	
	int M = v[0];
	for (int i = 1; i <= N - 1; i++) {

		M = gcd(M, v[i]);
	}
	ans.push_back(M);
	for (int n = 2; n <= sqrt(M); n++) {

		if (M % n == 0) {
			cout << n << " ";
			if (n == M / n)continue;
			ans.push_back(M / n);
		}
	}

	sort(ans.begin(), ans.end());

	for (int a : ans) {
		cout << a << ' ';
	}

	cout << "\n";
	return 0;

}
