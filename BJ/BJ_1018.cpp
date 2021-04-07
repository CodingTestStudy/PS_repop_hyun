#include <iostream>
#include <string>
using namespace std;
int N, M;
int ans = 0x3f3f3f3f;
char arr[51][51];

char b[8][8] = { {'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'}

};
char w[8][8] = { {'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'}

};


int black(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[y + i][x + j] != b[i][j])++cnt;
		}
	}
	return cnt;
}
int white(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[y + i][x + j] != w[i][j])++cnt;
		}
	}

	return cnt;
}

void checking(int y, int x) {


	int ret = min(black(y, x), white(y, x));
	ans = min(ret, ans);
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	string inn;
	for (int i = 0; i < N; i++) {
		cin >> inn;
		for (int j = 0; j < M; j++) {
			arr[i][j] = inn[j];
		}
	}




	for (int i = 0; i < N; i++) {
		if (i + 8 > N)continue;
		for (int j = 0; j < M; j++) {
			if (j + 8 > M)continue;
			checking(i, j);
		}
	}


	cout << ans << '\n';
	return 0;
}