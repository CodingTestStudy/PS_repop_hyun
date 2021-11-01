#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
using ll = long long;
#define MAXN 4000
int N;
ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];
vector<ll> a, b;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> A[i] >> B[i] >> C[i] >> D[i];

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			ll t = A[i] + B[j];
			ll t2 = C[i] + D[j];
			
			a.push_back(t);
			b.push_back(t2);

		}
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	ll ans = 0;
	
	for (int i = 0; i < a.size(); i++) {

		ll down = lower_bound(b.begin(), b.end(), -a[i]) - b.begin();
		ll up = upper_bound(b.begin(), b.end(), -a[i]) - b.begin();
	
		ans += up - down;

	}
	cout << ans << '\n';
	return 0;

}