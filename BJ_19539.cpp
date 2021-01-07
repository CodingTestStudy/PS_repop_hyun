//백준 사과나무
//수학적 사고 필요 
#include <iostream>
using namespace std;

int N;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];
	}

	int d = 0;
	int r = 0;
	
	for (int i = 0; i < N; i++) {
		d += arr[i] / 2;
		r += arr[i] % 2;

	}
	if (d < r)cout << "NO" << '\n';
	
	else {

		int ret = (d - r) % 3;
		if (ret == 0)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;

}