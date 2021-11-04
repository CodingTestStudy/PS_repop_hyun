#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 200
int N;
int arr[MAXN + 1];
vector<int>ret;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> arr[i];
	}

	ret.push_back(arr[0]);
	for (int i = 1; i < N; i++) {

		if (ret.back() < arr[i]) {
			ret.push_back(arr[i]);

		}

		else {
			*lower_bound(ret.begin(), ret.end(), arr[i]) = arr[i];
			
		}
		

	}

	cout << N - ret.size() << '\n';
	return 0;

}