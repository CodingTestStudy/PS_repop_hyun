#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
int N;
int arr[1000001];
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	v.push_back(arr[0]);

	for (int i = 1; i < N; i++) {

		if (v.back() < arr[i]) {
			
			v.push_back(arr[i]);

		}
		else if (v.back() > arr[i]) {

			vector<int>::iterator f = lower_bound(v.begin(), v.end(), arr[i]);
			*f = arr[i];
		
			
			

		}
	}

	cout << v.size() << '\n';
	return 0;

}