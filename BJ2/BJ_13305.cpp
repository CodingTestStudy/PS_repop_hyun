#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, pair<int, ll>> P; //기름과 위치와 남은거리
#define MAXN 100000
vector<P> v;
ll sum[MAXN + 2];
int N;

bool comp(P& a, P& b) {

	return a.first < b.first;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sum[0] = sum[1] = 0;
	cin >> N;

	for (int i = 1; i <= N - 1; i++) {
		ll tmp;
		cin >> tmp;
		sum[i + 1] = sum[i] + tmp;


	}


	for (int i = 1; i <= N; i++) {
		ll tmp;
		cin >> tmp;
		v.push_back({ tmp,{i,sum[N] - sum[i]} });


	}

	sort(v.begin(), v.end(), comp);
	ll ans = 0;
	int lastPos = N;
	for (const P& s : v) {

		if (s.second.first > lastPos || s.second.first == N)continue;
		else {
			ans += s.first * (s.second.second - (sum[N]-sum[lastPos]));
			lastPos = s.second.first;


		}


	}


	cout << ans << '\n';
	return 0;
}