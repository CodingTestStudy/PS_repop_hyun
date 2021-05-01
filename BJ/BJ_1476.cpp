#include <iostream>
using namespace std;
int E, S, M;
int ans = 1;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> E >> S >> M;
	int e=1, s=1, m=1;
	while (1) {
		if (e == E && s == S && m == M)break;
		e += 1;
		s += 1;
		m += 1;
		
		if (e > 15) {
			e = 1;
		}
		if (s > 28) {
			s = 1;
		}
		if (m > 19) {
			m = 1;
		}
		ans++;

	
	}

	cout << ans << '\n';
	return 0;

}