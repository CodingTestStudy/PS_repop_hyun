#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
int arr[1005];
int Sarr[1005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N+1);
	Sarr[0] = 0;
	for (int i = 1; i <= N; i++) {
		Sarr[i] = arr[i] + Sarr[i - 1];
	}
	int ans=0;
	bool flag = 0;
	for (int i = 0; i < N; i++) {

		if (Sarr[i] + 1 < arr[i + 1]) {
			ans = Sarr[i] + 1;
			flag = 1;
			break;
		}
	}
	if (!flag) { //모두 가능
		ans = Sarr[N] + 1;
	}
	cout << ans << '\n';
	return 0;

}