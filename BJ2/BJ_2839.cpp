#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
const int INF = 0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int ans = INF;
	int a, b;
	a = N / 5;
	b = N / 3;
	while (1) {
		for (int i = 0; i <= b + 1; i++) {

			if (a * 5 + 3 * i == N) {
				ans = ans < a + i? ans : a+i;
			}
		}
		a--;
		if (a < 0)break;
	}

	
	if (ans == INF)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;

}