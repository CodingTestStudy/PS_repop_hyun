
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
int N;
ll S;
ll arr[50002];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	S = 0;
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		S += arr[i];
	
	}

	
	int lo = 0;
	int hi = 0;
	ll sum = arr[lo];
	while (lo <= hi && hi <N) {
		
		if (sum < S - (sum)) {
			ret = max(ret, sum);
			hi++;
			sum += arr[hi];
		
		}
		else {
			ret = max(ret, S - (sum));
			sum -= arr[lo];
			lo++;
			
		}

	}
	cout << ret << '\n';
	return 0;

}
