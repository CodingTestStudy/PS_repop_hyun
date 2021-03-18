//백준 5904 moo
#include <iostream>
using namespace std;

int L[100];
int N;

void find(int st , int ed,int k) {

	if (N == st || N == st + L[k - 1] || N == st + k+3 + L[k - 1]) {
		cout << "m\n";
		return;
	}
	else {
		if (st < N && N < st + L[k - 1]) {
			find(st, st + L[k - 1],k - 1);
		}
		else if (st + L[k - 1] < N && N < st + k + 3 + L[k - 1]) {
			cout << "o\n";
			return;
		}

		else if (st + k + 3 + L[k - 1] < N) {
			find(st + k + 3 + L[k - 1],ed,k - 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	L[0] = 3;
	int l = 3; int cnt = 0;
	while (1) {
		if (N < l)break; 
		cnt++;
		l = 2 * l + cnt + 3;
		L[cnt] = l;
	}

	find(1,L[cnt],cnt);
	return 0;

}