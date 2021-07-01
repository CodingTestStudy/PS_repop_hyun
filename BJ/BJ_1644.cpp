#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N;
vector<int>prime;
bool p[4500001];
void make_prime(int n) {
	memset(p, false, sizeof(p));
	for (int i = 2; i <= n; i++) {
		if (p[i])continue;
		prime.push_back(i);
		for (int j = i + i; j <= n; j += i) {
			p[j] = true;
		}

	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	if (N == 1) { cout << 0 << '\n'; return 0; }
	if (N == 2) { cout << 1 << '\n'; return 0; }
	make_prime(4500000);
	int ans = 0;
	int L = 0;
	int R = 1;
	int sum = prime[L] + prime[R];
	while (L <= R) {
		if (sum == N) {
			ans += 1;
		}

		if (sum < N) {
			R += 1;
			sum += prime[R];
		}
		else if (sum >= N) {
			sum -= prime[L];
			L += 1;
		
		}

		
	}
	


	cout << ans << '\n';
	return 0;

}

