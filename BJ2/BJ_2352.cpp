#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
int arr[40001];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> arr[i];

	}

	v.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		int b = v.back();
	
		if (b < arr[i]) {
			v.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), arr[i])-v.begin();
			v[idx] = arr[i];

		}

	}
	cout << v.size() << '\n';
	return 0;

}
