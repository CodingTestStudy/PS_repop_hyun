#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N, M;
vector<int> v;
vector<int>idx;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int a;
	
	for (int i = 0; i < N; i++) {

		cin >> a;
		v.push_back(a);

	}
	
	for (int i = 0; i < N-3; i++) {
		idx.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		idx.push_back(1);
	}
	
	sort(idx.begin(), idx.end());
	int ans = 0;
	do {
		int tmp = 0;
	
		for (int i = 0; i < N; i++) {
			if (idx[i] == 1)tmp += v[i];
		}
		
		if (tmp <= M) {
			ans = max(ans, tmp);
		}

	} while (next_permutation(idx.begin(), idx.end()));


	cout << ans << '\n';
	return 0;

}