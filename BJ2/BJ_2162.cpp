#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 3000
typedef pair<int, int> P;
int N;
int par[MAXN + 1];
int cnt[MAXN + 1]; //그룹의 선분 갯수
vector <pair<P,P>> v;
int find(int a) {
	if (par[a] < 0)return a;
	par[a] = find(par[a]);
	return par[a];
}
void merge(int a, int b) { //a가 부모

	a = find(a);
	b = find(b);
	if (a == b)return;
	par[b] = a;

}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}


bool check(int L1,int L2) {

	P a = v[L1].first;
	P b = v[L1].second;
	
	P c = v[L2].first;
	P d = v[L2].second;

	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) { //평행할때
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}

	return ab <= 0 && cd <= 0;
}
void solve() {
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {

			if (check(i, j)) {
				merge(i, j);
			}
		}
	}

	int gCnt = 0;
	int maxCnt = 0;
	for (int i = 0; i < N; i++) {

		if (find(i) == i)gCnt++;
		cnt[find(i)] += 1;
		if (cnt[find(i)] > maxCnt)maxCnt = cnt[find(i)];

		
	}
	
	cout << gCnt << '\n';
	cout << maxCnt << '\n';
}

void init() {
	memset(par, -1, sizeof(par));
	memset(cnt, 0, sizeof(cnt));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		v.push_back({ {a,b},{c,d} });
		cnt[i] = 0;

	}


	solve();
	return 0;

}