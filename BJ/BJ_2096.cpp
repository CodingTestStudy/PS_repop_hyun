#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[100000 + 1][3];
int dpMax[3] = { 0 };
int dpMin[3] = { 0 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	int a, b, c;
	for (int i = 0; i < N; i++) {
		
		
		a = max(dpMax[0] + arr[i][0], dpMax[1] + arr[i][0]);
		b = max(dpMax[0] + arr[i][1], max(dpMax[1] + arr[i][1], dpMax[2] + arr[i][1]));
		c = max(dpMax[1] + arr[i][2], dpMax[2] + arr[i][2]);
		dpMax[0] = a;
		dpMax[1] = b;
		dpMax[2] = c;

		a = min(dpMin[0] + arr[i][0], dpMin[1] + arr[i][0]);
		b = min(dpMin[0] + arr[i][1], min(dpMin[1] + arr[i][1], dpMin[2] + arr[i][1]));
		c = min(dpMin[1] + arr[i][2], dpMin[2] + arr[i][2]);

		dpMin[0] = a;
		dpMin[1] = b;
		dpMin[2] = c;
	}


	cout << max(dpMax[0], max(dpMax[1], dpMax[2])) << ' ' << min(dpMin[0], min(dpMin[1], dpMin[2])) << '\n';

	return 0;

}