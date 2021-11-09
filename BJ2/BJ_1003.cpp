#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
int N;
int T;
int dpOne[40 + 5];
int dpZero[40 + 5];
int fibo_One(int n) {
	
	if (n == 0)return 0;
	if (n == 1)return dpOne[n] = 1;

	if (dpOne[n] != -1)return dpOne[n];	
	int& ret = dpOne[n];
	ret = 0;
	ret += fibo_One(n - 1) + fibo_One(n - 2);
	return ret;

}
int fibo_zero(int n) {
	if (n == 0)return dpZero[n] = 1;
	if (n == 1)return 0;

	if (dpZero[n] != -1)return dpZero[n];
	int& ret = dpZero[n];
	ret = 0;
	ret += fibo_zero(n - 1) + fibo_zero(n - 2);
	return ret;
}
void solve() {

	cin >> N;

	cout << fibo_zero(N) << " " << fibo_One(N) << '\n';
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dpOne, -1, sizeof(dpOne));
	memset(dpZero, -1, sizeof(dpZero));
	cin >> T;
	while (T--)solve();
	return 0;

}