//백준 15998 카카오머니
//아이디어보다는 확실한 구현이 중요
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const long long MAX = pow(10, 18);

typedef long long ll;

unsigned long long gcd(ll a, ll b) {

	if (b == 0)return a;
	
	return gcd(b, a % b);
}
int N;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	ll exNet;
	ll M = 1LL;
	ll recharge;
	ll prev = 0LL;
	ll a;
	ll b = 0LL;
	bool flag = 0;
	for (int i = 0; i < N; i++) {
		
		prev = b;
		cin >> a >> b;
		if (prev + a < 0LL && M > 0) {
			if (!flag) {
				M = b - a - prev;
				exNet = b;
				flag = 1;
			}
			else {
				recharge = b - a - prev;
				M = gcd(recharge, M);
				exNet = max(exNet, b);
				if (M <= exNet) {
					M = -1LL;
				}
			}
		}
		else {
		
			//로그 입력 유효성 검사
			if (prev + a != b) {
				M = -1;
			}

		}

	
	}

	cout << M << '\n';
	return 0;

}
