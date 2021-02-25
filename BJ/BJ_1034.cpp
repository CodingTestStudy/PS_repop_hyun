#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[51][51];
int N, M,K;

bool isSameRow(int a,int b) {


	for (int i = 0; i < M; i++) {
		if (arr[a][i] != arr[b][i]) {
			return false;
		}
		else continue;
	}

	return true;
	
}

void solve() {

	int ret = 0;
	for (int i = 0; i < N; i++) {
		int cntZero = 0;
		
		for (int j = 0; j < M; j++) {
			
			if (arr[i][j] == 0) {
				++cntZero;
			}

		}

		if (cntZero <= K && cntZero % 2 == K % 2) {
			int tmp = 0;
			for (int a = 0; a < N; a++) {
				if (isSameRow(i, a)){
					++tmp; //같은 행인 갯수 셈
				}
			}
			ret = max(tmp, ret);
		}

	
	}
	

	cout << ret << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(arr, -1, sizeof(arr));
	string inn;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inn;
		for (int j = 0; j < M; j++) {
			arr[i][j] = inn[j] - 48;
		}
	}
	cin >> K;
	solve();

	return 0;

}