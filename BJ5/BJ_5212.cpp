#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <utility>
using namespace std;
char arr[20][20];
int yy[4] = { -1,1,0,0, };
int xx[4] = { 0,0,-1,1 };
#define MAX 0x3f3f3f3f
#define MIN -0x3f3f3f3f

int R, C;
vector<pair<int, int>> cordi;
vector<pair<int, int>> willFlushed;
int LY, LX, RY, RX;

bool compO(const  pair<int,int> & a, const  pair<int, int>& b) {
	
	if (a.first == b.first)return a.second < b.second;
	else return a.first > b.first;
}

bool compT(const  pair<int, int>& a, const  pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	else
	{
		return a.first < b.first;
	}
}

bool isSustained(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {

		int n_y = y + yy[i];
		int n_x = x + xx[i];

		if (0 <= n_y && n_y < R && 0 <= n_x && n_x < C) {

			if (arr[n_y][n_x] == 'X') {
				cnt += 1;
			}
		}
		
	}

	//주변에 섬이 2개 이상이면
	if (cnt >= 2)return true;

	else return false;
}

void checkingX() {

	

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (arr[i][j] == 'X') {
				cordi.push_back({ i,j }); //살아남은 섬들
			}

		}
	}

}

void flushing() {
	

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
		
			if (arr[i][j] == 'X') {
				if (isSustained(i, j))continue;
				else
				{
					willFlushed.push_back({ i,j });//물에 잠김
				}
			}

		}	
	}


	for (pair<int, int> p : willFlushed) {
		arr[p.first][p.second] = '.';
	}


	checkingX();


}


void findSmallest() {
	LY = MAX;
	LX = MAX;
	RY = MIN;
	RX = MIN;
	
	for (pair<int, int> p : cordi) {

		LY = min(LY, p.first);
		LX = min(LX, p.second);
		
		RY = max(RY, p.first);
		RX = max(RX, p.second);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			arr[i][j] = tmp[j];

		}
	}

	flushing();

	
	findSmallest();


	for (int i = LY; i <= RY; i++) {
		for (int j = LX; j <= RX; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;

}