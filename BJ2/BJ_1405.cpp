#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int yy[4] = { -1,1,0,0 };
int xx[4] = { 0,0,-1,1 };
int n;
bool visited[103][103];
double dir[4];
double E, W, S, N;
double ans = 0;
void dfs(int y, int x,int curN,double ret) {

	if (curN == n) {
		
		ans += ret;
		return;
	}


	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int n_y = y + yy[i];
		int n_x = x + xx[i];
		if (!visited[n_y][n_x]) {
			double next = ret * dir[i];
			dfs(n_y, n_x, curN + 1, next);
		}

	}

	visited[y][x] = 0;

	

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, 0, sizeof(visited));
	cin >> n;
	cin >> E >> W >> S >> N;
	dir[0] = N/100;
	dir[1] = S/100;
	dir[2] = W/100;
	dir[3] = E/100;

	dfs(50,50,0,1);
	cout << fixed;
	cout.precision(10);
	cout << ans << '\n';
	return 0;

}