//백준 3085 BOMBONI
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[51][51];
int N;
int ret = 0;
void check() {
	int cnt = 1;
	//행 체크
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < N - 1; j++) {
			
			if (arr[i][j] == arr[i][j + 1]) {
				cnt++;
			}
			else {
				ret = max(cnt, ret);
				cnt = 1;
			}
		}

		ret = max(cnt, ret);
		cnt = 1;
	}

	cnt = 1;
	//열 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (arr[j][i] == arr[j+1][i]) {
				cnt++;
			}
			else {
				ret = max(cnt, ret);
				cnt = 1;
			}
		}
		ret = max(cnt, ret);
		cnt = 1;
	}

}
void swapAndCheck(int x,int y,int a,int b) { //swap a and b 해서 체크하고 다시 돌려놓기
	//swap
	char tmp = arr[x][y];
	arr[x][y] = arr[a][b];
	arr[a][b] = tmp;

	check();

	//원위치
	tmp = arr[x][y];
	arr[x][y] = arr[a][b];
	arr[a][b] = tmp;



}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			arr[i][j] = input[j];
		}
	}
	
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N-1; j++) {
			
			swapAndCheck(i, j, i, j + 1);
			swapAndCheck(i,j,i + 1,j);
			if (ret == N) { //N보다 클수는 없으므로 더이상 찾지 않는다.
				cout << ret << '\n';
				return 0;
			}
		}
	}
	//마지막 줄 옆으로 바꾸기
	for (int i = 0; i < N - 1; i++) {
		swapAndCheck(N - 1, i, N - 1, i + 1);
	}

	cout << ret << '\n';
	return 0;
}