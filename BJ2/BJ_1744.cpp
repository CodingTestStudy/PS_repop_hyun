#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
vector<int> v;
vector<int> mv;
bool comp(int& a, int &b) {

	return a > b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int inn;
		cin >> inn;
		if (inn <= 0) {
			mv.push_back(inn);
		}
		else v.push_back(inn);

	}

	sort(v.begin(), v.end(),comp);
	sort(mv.begin(), mv.end());
	int ans = 0;
	int cur = 0;
	int Vsize = v.size() - 1;
	int MVsize = mv.size() - 1;
	for (;cur < Vsize; cur += 2) {
		
		if (v[cur + 1] == 1) { //1일경우 곱하는것보다 그냥 더하는게 더 큼
			ans += v[cur] + v[cur + 1];
		}
		else ans += v[cur] * v[cur + 1];
			 
	}
	if (cur == Vsize)ans += v[cur];


	cur = 0;
	for (; cur < MVsize; cur += 2) {

		ans += mv[cur] * mv[cur + 1];


	}
	if (cur == MVsize)ans += mv[cur];


	cout << ans << '\n';
	return 0;

}