// 백준 20551 Sort 마스터 배지훈의 후계자
#include <iostream>
#include <algorithm>
using namespace std;


int N, M;
int arr[200001];
int Bin(int q) {

	int lo = 0;
	int hi = N-1;
	int ret = -1;
	while (lo <= hi) {

		int mid = (lo + hi) / 2;
		
		if (arr[mid] == q) {
			ret = mid;
			hi = mid - 1;
		}
		else if (q < arr[mid]) {

			hi = mid - 1;
		}

		else if (arr[mid] < q) {

			lo = mid + 1;
		}
	}


	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); //정렬
	//Query
	int q;
	for (int i = 0; i < M; i++) {
		cin >> q;
		cout << Bin(q) << '\n';

	}
	return 0;
}