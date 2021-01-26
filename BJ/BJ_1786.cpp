//백준 1786 찾기
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 1000001;
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	string T, P;
	int M, N;

	getline(cin, T, '\n');
	getline(cin, P, '\n');

	N = T.length();
	M = P.length();


	int fail[MAX] = {0,};

	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j])fail[i] = ++j;

	}

	vector<int> ret;
	for (int i = 0, j = 0; i < N; i++) {

		while (j > 0 && T[i] != P[j]) j = fail[j - 1];

		//현재 글자 일치
		if (T[i] == P[j]) {

			//P에 해당하는 일치 부분을 T에서 찾음
			if (j == M - 1) {
				ret.push_back(i - M + 2);
				j = fail[j];
			}

			else j++;
		}
	}


	cout << ret.size() << '\n';
	for (int i : ret) {
		cout << i << " ";
	}
	return 0;
}