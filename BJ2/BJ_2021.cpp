#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
typedef  long long ll;
using namespace std;
int N;
vector<ll> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);

	}

	sort(v.begin(), v.end());
	ll answer = 0;
	ll num = 1;
	for (ll e : v) {
		
		answer += abs(e - num);
		num += 1;
		
	}

	cout << answer << '\n';
	return 0;

}
