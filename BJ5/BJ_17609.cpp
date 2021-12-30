#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
int T;
bool isOne = 0;
void left(string& a,int l ,int h) {
	bool flag = 0;
	while (l <= h) {
		if (a[l] == a[h]) {
			l++;
			h--;
		}

		else {
			flag = 1;
			break;
		}
	}

	if (!flag)isOne = 1;
	
}

void right(string& a,int l, int h) {
	bool flag = 0;
	while (l <= h) {
		if (a[l] == a[h]) {
			l++;
			h--;
		}
		else {
			flag = 1;
			break;
		}

	}
	if (!flag)isOne = 1;
}


void solve() {

	string a;
	cin >> a;
	
	isOne = 0;
	int lo = 0;
	int hi = a.length() - 1;
	bool isZero = 1;
	while (lo <= hi) {

		if (a[lo] == a[hi]) {
			lo++;
			hi--;
		}

		else {
			isZero = 0;//0 아님
			left(a,lo+1,hi); //왼쪽 통과
			right(a,lo,hi-1);//오른쪽 통과
			break;
		}


	}

	if (isZero)cout << 0 << '\n';
	else {
		
		if (isOne) {
			cout << 1 << '\n';
		}
		else cout << 2 << '\n';
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;

}