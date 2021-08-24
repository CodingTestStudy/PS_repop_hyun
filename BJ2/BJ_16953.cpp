#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, int> p;
priority_queue<p,vector<p>,greater<p>>pq;
set<ll> s;
ll A, B;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B;
	
	pq.push({ A ,0});
	s.insert(A);
	int ans = 0;
	while (!pq.empty()) {
		ll t = pq.top().first;
		int cnt = pq.top().second;
		pq.pop();
		s.insert(t);
		ll a = t * 2;
		ll b = t * 10 + 1;
		if (t == B) {
			ans = cnt;
			break;
		}
		auto f = s.find(a);
		if (f == s.end()) {
			if (a > B)continue;
			pq.push({a,cnt+1});
		}
		f = s.find(b);
		if (f == s.end()) {
			if (b > B)continue;
			pq.push({b,cnt+1});
		}
	

	}
	if (ans == 0)cout << -1 << '\n';
	else cout << ans+1 << '\n';
	return 0;

}