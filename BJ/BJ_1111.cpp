//백준 1111 IQ 테스트
// 수열은 나열이 기본
#include <iostream>
#include <cmath>
using namespace std;
int arr[52];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (n >= 3) {
		int A;
		int B;
		// 이땐 오로지 A = 1 B = 0 일때만 구할 수 있음
		if (arr[2] == arr[1]) {
			A = 1;
			B = 0;
		}
		else {
			A = (arr[3] - arr[2]) / (arr[2] - arr[1]);
			B = arr[2] - arr[1] * A;
		}

		bool isB = false;
		for (int i = 1; i <= n - 1; i++) {
			if (arr[i + 1] != arr[i] * A + B) {
				cout << "B" << '\n';
				isB = true;
				break;
			}
		}
		
		if (isB == false) {
			cout << arr[n] * A + B << '\n';

		}
	}

	else if (n == 1) {

		cout << "A" << '\n';
	}

	else if (n == 2) { 
		//두개밖에 안주어졌을 땐, 오로지 A = 1 B = 0 일때만 구할 수 있음
		if (arr[1] == arr[2])cout << arr[1] << '\n';
		else cout << "A" << '\n';
	}
	return 0;

}
