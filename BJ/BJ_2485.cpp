//백준 2485 가로수
#include <iostream>
using namespace std;
int N;

int gcd(int a, int b) {
	if (b == 0)return a;

	return gcd(b, a % b);
}


int findGcd(int arr[], int n) {
	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		ans = gcd(arr[i], ans);
	}

	return ans;
}
int arr[100001];
int diff[100001];
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int ret = 0;
	for (int i = 0; i < N; i++) {
	
		cin >> arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		diff[i] = arr[i + 1] - arr[i];
	}

	int g = findGcd(diff, N-1);

	for (int i = 0; i < N - 1; i++) {
		ret += (diff[i] / g) - 1;
	}

	cout << ret << '\n';
	return 0;

}