
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int T;

int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };
#define range(y,x) if(0<= x && x < 3 && 0<= y && y < 3)
bool visited[4][4];


int ans;
int arr[3][3];
vector<int> ret;
int tArr[3][3];
void dfs(int k) {
	
	if (k == 9) {
		memset(tArr, 0, sizeof(tArr));
		for (int i = 0; i < ret.size(); i++) {
			
			int k = ret[i];
			int y = k / 3;
			int x = k % 3;
			tArr[y][x] += 1;
			for (int j = 0; j < 4; j++) {
				
				int n_y = y + yy[j];
				int n_x = x + xx[j];
				range(n_y, n_x) {
					
					tArr[n_y][n_x] += 1;
					
				}
			}
			
			
		}

		bool flag = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != tArr[i][j] % 2) {
					flag = 1;
					break;
				}
			}
		}
		

		if (flag)return;

		else {
			ans = min(ans, (int)ret.size());
			return;
		}

	}


	ret.push_back(k);
	dfs(k + 1);
	ret.pop_back();
	dfs(k + 1);

}
void solve() {

	ret.clear();
	ans = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == '*') {
				arr[i][j] = 1;
			}
			else arr[i][j] = 0;
		}
	}

	dfs(0);

	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)solve();
	return 0;

}