//백준 16918 봄버맨

#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int arr[201][201];
int R, C, N;
queue<pair<int, int>> q;
//상하좌우
int y[4] = { -1,1,0,0 };
int x[4] = { 0, 0, -1, 1 };

void Boom(int yy, int xx) {

	for (int i = 0; i < 4; i++) {
		int n_y = yy + y[i];
		int n_x = xx + x[i];
		if (0 <= n_y && n_y < R && 0 <= n_x && n_x < C) {
			q.push({ n_y,n_x });
		}
		
	}

}
void New() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
		
			if (arr[i][j] == 0) {
				arr[i][j] = 2;
			}
		}

	}

}

void Exe() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 2) {
				arr[i][j] = 1;
			}
			else if (arr[i][j] == 1) {
				
				arr[i][j] = 0;
				Boom(i, j); //폭탄 터질 위치들 저장
			}
		}

	}
	//실제 터짐
	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		arr[y][x] = 0; //터짐 
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string input;
	cin >> R >> C >> N;


	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			if (input[j] == '.') {
				arr[i][j] = 0;
			}
			else if(input[j] == 'O'){
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {

		if (i % 2 == 1) {
			New();//새로 설치
		}
		else {

			Exe(); //터짐
		}
	}

	//결과
	for (int i = 0; i < R; i++) {
	
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 0) {
				cout << '.';
			}
			else  { //1 or 2이면 폭탄
				cout << 'O';
			}
		}

		cout << '\n';
	}
	
	return 0;

}

