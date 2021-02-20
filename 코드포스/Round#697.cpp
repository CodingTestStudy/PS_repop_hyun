//Codeforces Round #697 (Div. 3) 
// B. New Year's Number
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int q;
		int r;
		q = n / 2020;
		r = n % 2020;
		if (q < r) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;

}
