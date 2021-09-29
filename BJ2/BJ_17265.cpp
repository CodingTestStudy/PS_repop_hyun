#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int MIN = -0x3f3f3f3f;
int yy[2] = { 1,0 };
int xx[2] = { 0,1 };
char arr[6][6];
int maxVal = MIN;
int minVal = MAX;
int N;
void dfs(int y, int x, int sum,char op) {
	int num = arr[y][x] - '0';
	if (y == N && x == N) {
		int ret = sum;
		if (op == '*') {
			ret *= num;
		}
		else if (op == '+') {

			ret += num;
		}
		else if (op == '-') {
			ret -= num;
		}
		
		maxVal = max(maxVal, ret);
		minVal = min(minVal, ret);
		return;
	}

	if (num < 0) { //부호
		
		for (int i = 0; i < 2; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];
			if (0 < n_y && n_y <= N && 0 < n_x && n_x <= N) {
				dfs(n_y, n_x, sum, arr[y][x]); //현재 부호와 함께
			}
		}
		
	}
	else if (num >= 0) { //숫자
		int ret = num;
		
		if (op != 0) {
			ret = sum;
			if (op == '*') {
				ret *= num;
			}
			else if (op == '+') {

				ret += num;
			}
			else if (op == '-') {
				ret -= num;
			}
		
		}
	
		for (int i = 0; i < 2; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];
			if (0 < n_y && n_y <= N && 0 < n_x && n_x <= N) {
				dfs(n_y, n_x, ret, '\0'); //현재 부호와 함께
			}
		}
	}
	

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(1, 1,0,'\0');
	cout << maxVal << " " << minVal << '\n';
	return 0;

}