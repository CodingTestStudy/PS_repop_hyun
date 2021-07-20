#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector<long long> a;
vector<long long> b;

long long A_arr[1001];
long long B_arr[1001];
long long sum_Aarr[1001] = { 0, };
long long sum_Barr[1001] = { 0, };
long long T;
int n, m;
long long ans = 0;
void make_a() {
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			a.push_back(sum_Aarr[j] - sum_Aarr[i]);
		}
	}
}

void make_b() {
	for (int i = 0; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			b.push_back(sum_Barr[j] - sum_Barr[i]);
		}
	}
}

void solve() {

	make_a();
	make_b();

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++) {
		auto u = upper_bound(b.begin(), b.end(), T - a[i]);
		auto l = lower_bound(b.begin(), b.end(), T - a[i]);
		if (u != l)ans += u - l;
		
	}

	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A_arr[i];
		sum_Aarr[i] = sum_Aarr[i - 1] + A_arr[i];
	}
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> B_arr[i];
		sum_Barr[i] = sum_Barr[i - 1] + B_arr[i];
	}

	solve();
	return 0;

}