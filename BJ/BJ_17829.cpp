//백준 17829 222-풀링
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1025][1025];
int N;
int dived(int a, int b) {

	vector<int>v;
	for (int i = a; i < a + 2; i++) {
		for (int j = b; j < b + 2; j++) {
			v.push_back(arr[i][j]);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	return v[1];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (N > 1) {
		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				arr[i / 2][j / 2] = dived(i, j);
			}
		}

		N /= 2;
	}

	cout << arr[0][0] << '\n';
	return 0;

}