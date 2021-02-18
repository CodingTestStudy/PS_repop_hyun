//폭탄 던지는 태영이 시간초과 코드
// 시간복잡도 O(N^2*M^2)이다;;
/*
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M;
int H[2001][2001];
int ans[2001][2001];
const int INF = -2'147'483'648;
void check(int y, int x) {

	//가운데 폭탄갯수 체크
	int bomb = H[y][x];
	

	bomb = -bomb;

	int midY = y + (M / 2);
	int midX = x + (M / 2);
	ans[midY][midX] += bomb; //폭탄 갯수 증가

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			
			H[y + i][x + j] += bomb; //갱신

		}
	}


	
}
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(H, 0, sizeof(H));
	memset(ans, 0, sizeof(ans));
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> H[i][j];
		}
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + M <= N && j + M <= N) {
				if (H[i][j] < 0)check(i, j);

				else continue;
			}
			
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;

}*/



#include <iostream>
#include <string.h>


using namespace std;
int N, M;

long long H[2001][2001];
long long ans[2001][2001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long num; cin >> num;
			H[i][j] = -num; //H[i][j]는 m*m 범위에 있는 폭탄의 총 갯수임
		}
	}

	int r = M / 2;
	int st = r;
	int end = N - r;
	
	for (int i = st; i < end; i++) {
		for (int j = st; j < end; j++) {
			ans[i][j] = H[i - r][j - r];
			if (i - r - 1 >= 0)
				ans[i][j] -= H[i - r - 1][j - r];
			if (j - r - 1 >= 0)
				ans[i][j] -= H[i - r][j - r - 1];
			if (i - r - 1 >= 0 && j - r - 1 >= 0)
				ans[i][j] += H[i - r - 1][j - r - 1];
			if (i - M >= 0)
				ans[i][j] += ans[i - M][j];
			if (j - M >= 0)
				ans[i][j] += ans[i][j - M];
			if (i - M >= 0 && j - M >= 0)
				ans[i][j] -= ans[i - M][j - M];

		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;

}