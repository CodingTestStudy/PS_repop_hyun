//백준 10816 숫자카드 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;
int N;
int M;
vector<int> v;
map<int, int> m; //한번 계산한거는 또 계산하지 않음

void bin(int q,int lo, int hi) {
	if (lo >= hi) {
		int j = lo;
		int cnt = 0;
		while (j < N) {
			if (v[j] == q)cnt++;

			else break;

			j++;

		}
		m.insert({ q,cnt });
		cout << cnt << " ";
		return;
	}

	int mid = (lo + hi) / 2;

	if (v[mid] < q) {
		bin(q, mid+1, hi);
	}
	else if (q <= v[mid]) {
		bin(q, lo, mid);
	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int inn;
	for (int i = 0; i < N; i++) {
		cin >> inn;
		v.push_back(inn);

	}

	sort(v.begin(), v.end());


	cin >> M;
	int query;
	
	for (int i = 0; i < M; i++) {
		cin >> query;
		auto f = m.find(query);
		if (f != m.end()) { //이미 한번 계산한거 또 안함
			cout << m[query] << " ";
		} 
		else bin(query,0,N-1);
	}
	return 0;

}