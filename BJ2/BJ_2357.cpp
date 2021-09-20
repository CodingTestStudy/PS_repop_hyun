#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
const int MAX = 0x3f3f3f3f;
int N, M;
ll arr[100002];
ll* maxTree;
ll* minTree;
ll init(int node, int st,int ed, bool maxT) {

	if (st == ed) {
		if (maxT) return maxTree[node] = arr[st];
		else return minTree[node] = arr[st];
	}

	ll mid = (st + ed) / 2;

	if (maxT)return maxTree[node] = max(init(node * 2, st, mid, 1), init(node * 2 + 1, mid + 1, ed, 1));
	else return minTree[node] = min(init(node * 2, st, mid, 0), init(node * 2 + 1, mid + 1, ed, 0));


}

ll find(int node, int fS,int fE,int st, int ed, bool maxT) {

	if (fE < st || fS > ed) {
		if (maxT)return -MAX;
		return MAX;
	}

	if (fS <= st && ed <= fE) {
		if (maxT) return maxTree[node];
		else return minTree[node];
	}

	ll mid = (st + ed) / 2;
	if (maxT)return max(find(node * 2, fS, fE, st, mid, 1), find(node * 2 + 1, fS, fE, mid + 1, ed, 1));
	else return min(find(node * 2, fS, fE, st, mid, 0), find(node * 2 + 1, fS, fE, mid + 1, ed, 0));



}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int h = ceil(log2(N));
	minTree = new ll[1 << (h + 1)];
	maxTree = new ll[1 << (h + 1)];

	memset(minTree, MAX, sizeof(minTree));


	for (int i = 0; i < N; i++) {

		cin >> arr[i];
	}

	init(1, 0, N - 1, 1);
	init(1, 0, N - 1, 0);


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);

		cout << find(1, a-1, b-1, 0, N - 1, 0) << " " << find(1, a-1, b-1, 0, N - 1, 1) << '\n';
		

	}
	return 0;

}