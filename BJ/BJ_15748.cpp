//백준 15748 Rest Stops
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
ll L, N, rF, rB;
vector<pair<ll, ll>> v;


void solve() {

	ll taste = 0;
	ll dist = rF - rB;
	ll step = 0;

	for (int i = 0; i < v.size(); i++) {
		
		if (step < v[i].second) {
			taste += (v[i].second - step) * v[i].first * dist;
			step = v[i].second;

		}


	}


	cout << taste << '\n';

}
bool compare(pair<ll,ll> a , pair<ll,ll> b) {

	if (a.first == b.first)return a.second < b.second;

	else return a.first > b.first;

	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> N >> rF >> rB;
	
	ll x, c;
	for (int i = 0; i < N; i++) {
		cin >> x >> c;

		v.push_back({ c,x });
	}

	sort(v.begin(), v.end(),compare);
	

	solve();
	return 0;

}