#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int ans = 0;
	do {
		int tmp = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			tmp += abs(v[i] - v[i + 1]);
		}

		ans = max(tmp, ans);
		
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';
	return 0;

}