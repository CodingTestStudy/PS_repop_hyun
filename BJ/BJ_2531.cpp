// 백준 2531 회전초밥
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int C[3001]; //초밥
int arr[30001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(C, 0, sizeof(C));

	int N, d, k, c;

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int s = 0; int e = 0;
	int start, end; //루프 그만둘 시점 저장
	int ret = 0;
	while (k-- > 1) { //k 개 만큼 보기

		C[arr[e]]++;
		e = (e + 1) % N;
	}
	C[arr[e]]++;
	start = s; //시작 
	end = e; //시작

	while (1) {
		int cnt = 0;
		C[arr[s % N]]--;
		e = (e + 1) % N;
		s = (s + 1) % N;
		C[arr[e % N]]++;
	
		for (int i = 1; i <= d; i++) {
			if (C[i] > 0)++cnt;
		}
		if(C[c] == 0)++cnt;//c 추가

		ret = max(ret, cnt);
		if (start == s  && end == e)break;
	}

	cout << ret << '\n';
	return 0;
}