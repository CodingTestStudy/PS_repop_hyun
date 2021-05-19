#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ll;

// 1'000'000'007


vector<vector<ll>> cal(vector<vector<ll>>& a, vector<vector<ll>>& b) {
	
	vector<vector<ll>> ret(2,vector<ll>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += a[i][k] * b[k][j];
		
			}
			ret[i][j] %= 1'000'000'007;
		}
	}



	return ret;

	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N;
	cin >> N;

	vector<vector<ll>> f = { {1,1},{1,0} };
	vector<vector<ll>> ans = { {1,0},{0,1} };

	while (N > 0) {
		if (N % 2 == 1) {
			ans = cal(ans, f);

		}
		f = cal(f, f);
		N/= 2;

	}

	cout << ans[0][1] << '\n';
	return 0;

}