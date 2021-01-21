//BJ 2343 기타레슨 
#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	
	
	int lo = 0;
	int sum = 0;
	int hi;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		
		sum += a[i];
		lo = max(lo, a[i]);
	}
	
	
	hi = sum;
	while (lo < hi) {
		
		int cnt = 0;
		int tmp = 0;
		int mid = (hi + lo) / 2;
		for (int i = 1; i <= N; i++) {
			tmp += a[i];

			if (tmp > mid) { //블루레이 하나에 최대로 강좌 넣음
				cnt++;
				tmp = 0;
				i--;
			}
		}

		if (cnt >= M) {
			lo = mid + 1;
		}
		
		else {
			hi = mid;
		}

	}

	cout << lo << '\n';

	return 0;
}