//백준 7570 줄 세우기
#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[1'000'001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int>v;
	cin >> N;
	int inn;
	fill(arr, arr + N,0);
	for (int i = 1; i <= N; i++) {
		cin >> inn;
		arr[inn] = arr[inn - 1] + 1;

	}

	int ret = -987654321;
	for (int i = 1; i <= N; i++) {
		
		ret = max(ret, arr[i]);
	}

	cout <<N - ret << '\n';
	return 0;

}