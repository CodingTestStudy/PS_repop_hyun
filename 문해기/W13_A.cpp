#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
#define MAXN 3000

int N, M;
string s;
string arr[MAXN + 2];
string temp = "";
int fail[MAXN + 1];

void makeText() {
	//가로
	for (int i = 0; i < N; i++) {

		temp += arr[i];


		temp += "$";

	}
	//세로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp += arr[j][i];
		}

		temp += "$";

	}


	//대각
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N - i; j++) {

			temp += arr[j][i + j];
		}
		temp += "$";

	}


	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N - i; j++) {
			temp += arr[i + j][j];
		}

		temp += "$";

	}


}

void makeFail(string& a) {
	memset(fail, 0, sizeof(fail));
	for (int i = 1, j = 0; i < a.length(); i++) {

		while (j > 0 && a[i] != a[j])j = fail[j - 1];
		if(a[i] == a[j])fail[i] = ++j;

	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr[i] = s;
	
	}


	makeText();

	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		makeFail(a);
		bool flag = 0;
		for (int i = 0, j = 0; i < temp.length(); i++) {

			while (j > 0 && temp[i] != a[j])j = fail[j - 1];
			if (temp[i] == a[j]) {
				if (j == a.length() - 1) {
					cout << 1 << '\n';
					flag = 1;
					break;
				}
				else j++;
			}

			if (flag)break;
		}

		if (!flag)cout << 0 << '\n';

		
	}

	return 0;

}