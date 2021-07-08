#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int N, M;
vector<int>v;
vector<int>::iterator it;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);

	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		it = find(v.begin(), v.end(), input);
		
		if (it != v.end()) {
			cout << 1 << '\n';
		}
		else cout << 0 << '\n';
	}

	return 0;

}
