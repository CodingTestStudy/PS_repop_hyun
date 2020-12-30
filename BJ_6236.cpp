//BJ_6236 Monthly Expense
#include <iostream>
using namespace std;

#define ll long long
ll arr[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N, M;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	ll lo = 1;
	ll hi = 1'000'000'000;
	
	while (lo < hi) {
		bool noMore = false;
		ll mid = (hi + lo) / 2;
		ll sum = mid;
		ll cnt = 1;//맨 먼저 뽑아야됨
		for (int i = 0; i < N; i++) {
			sum -= arr[i];

			//써야하는데 남은 돈이 없을 때,
			if (sum < 0 ) {
				cnt++;
				sum = mid - arr[i];
				//새로 뽑아도 안되는 경우..안됨 하루에 두번 못뽑음
				if (sum < 0) {
					
					noMore = true;
					break;
				}
			}
		}


		if (cnt > M || noMore) { //더 크게 뽑아야 함
			lo = mid+1;
		}

		else { // cnt <= M 더 적은 금액뽑아서 M을 맞춰야함
			hi = mid;
		}
	}

	cout << lo << '\n';
	
	return 0;

}