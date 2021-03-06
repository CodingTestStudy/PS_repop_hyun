//백준 10815 숫자카드
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v;
	vector<int>m;
	int in;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> in;
		m.push_back(in);

	}
	
	for (int s : m) {
		
		if (binary_search(v.begin(), v.end(), s)) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}
	return 0;

}