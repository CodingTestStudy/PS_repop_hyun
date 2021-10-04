#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
#define MAXN 1'000'000
int N;
int arr[MAXN+10];
vector<int>v;
int idx[MAXN + 10]; //원본수열에서 i번째 숫자는 Lis에서 몇번째인지
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}



	for (int i = 1; i <= N; i++) {

		if (v.size() ==0 ||v[v.size()-1]< arr[i]) {

			v.push_back(arr[i]);
			idx[i] = v.size()-1;

		}
		else  {
			int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[pos] = arr[i];
			idx[i] = pos;

		}
	}

	cout << v.size() << '\n';
	vector<int>ans;
	int f = v.size()-1;
	for (int i = N; i > 0; i--) {

		if (idx[i] == f) {
			f--;
			ans.push_back(arr[i]);
			
		}
	}


	for (int i = ans.size() - 1; i >= 0; i--)cout << ans[i] << " ";
	cout << '\n';
	return 0;
}