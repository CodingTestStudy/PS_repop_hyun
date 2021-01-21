// 16287 Parcel
// 색다른 dp // 다시 풀기
#include<iostream>
using namespace std;
int weight[800000];
int arr[5001];
int W, n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> W >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//dp로 n^2으로 끝낼 수 있다.
	//a+b = w- c - d 로 2개씩 나눔으로써...
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			
			if (arr[i] + arr[j] > W)continue;
			else if(weight[W - arr[i] - arr[j]] > 0){
				cout << "YES" << '\n';
				return 0;
			}
		}
		for (int j = 0; j < i; j++) {
			if (arr[i] + arr[j] < W)weight[arr[i] + arr[j]] = 1;
		}

	}
	cout << "NO" << '\n';
	return 0;
}