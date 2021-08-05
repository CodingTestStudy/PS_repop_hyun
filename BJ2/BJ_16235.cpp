#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <deque>
using namespace std;

int yy[8] = { -1,-1,0,1,1,1,0,-1 };
int xx[8] = { 0,1,1,1,0,-1,-1,-1 };
int A[11][11]; //겨울마다 추가
int arr[11][11];
deque<int> t[11][11];
deque<int> dead[11][11];
int N, M, K;

void input() {

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			arr[i][j] = 5;
		}
	}
	for (int i = 1; i <= M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		t[r][c].push_back(age);
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(t[i][j].begin(), t[i][j].end());
		}
	}
	
}
int check() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!t[i][j].empty()) {

				ans += t[i][j].size();
			}
		}
	}
	return ans;
}

void aging(int y, int x) {
	

	int deadAfteridx = 2000;
	for (int i = 0; i < t[y][x].size(); i++) {
		
		if (arr[y][x] < t[y][x][i]) {
			deadAfteridx = i;
			break;
		}
		else if(arr[y][x] >= t[y][x][i]){
			
			arr[y][x] -= t[y][x][i];
			t[y][x][i] += 1;
		}

	
	}


	for (int i = t[y][x].size()-1; i >= deadAfteridx; i--) {
		dead[y][x].push_back(t[y][x].back());
		t[y][x].pop_back();
	}

}

void nutri(int y, int x) {
	
	for (int s : dead[y][x]) {
		arr[y][x] += (s >> 1);
	}

	dead[y][x].clear(); //죽은 나무들 모두 양분화됨
}

void grow(int y, int x) {

	for (int s : t[y][x]) {
		if (s % 5 == 0) {
			
			for (int i = 0; i < 8; i++) {
				int n_y = y + yy[i];
				int n_x = x + xx[i];
				if (1 <= n_y && n_y <= N && 1 <= n_x && n_x <= N) {
					t[n_y][n_x].push_front(1);
				
				}
				
			}


		}
	}
}

void springAndSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!t[i][j].empty()) {

				aging(i, j);
				if (!dead[i][j].empty()) { //죽은 나무 존재

					nutri(i, j);
				}
			}
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!t[i][j].empty()) { //나무 존재
	
				grow(i, j);
			}
		}
	}

}
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] += A[i][j];
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	input();
	
	while (K--) {
		springAndSummer(); 
	
		fall(); 
		winter();
	}

	int ans = 0;
	ans = check();
	cout << ans << '\n';

	



	return 0;

}
