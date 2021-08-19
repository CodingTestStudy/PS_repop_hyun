#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
#define MAXN 100000
vector<int>number;
int p[MAXN + 1];

int find(int a) {
	if (p[a] < 0) return a;
	p[a] = find(p[a]);

	return p[a];


}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[b] = a;
}

int G, P;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof(p));
	cin >> G >> P;
	int ans = 0;

	for (int i = 0; i < P; i++) {
		int num;
		cin >> num;
	
		number.push_back(num);
		

	}

	for (int i = 0; i < P; i++) {
		
		int n = number[i];
		int par = find(n);
		if (par == 0) {
			break;
		}
		
		else {
			ans += 1;
			merge(par-1, n); //par-1이 새로운 부모

		}
	}
	
	cout << ans << '\n';
	return 0;

}