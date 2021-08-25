#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> p;

class comp {

public:
	const bool operator () (p& a, p& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first < b.first; //true이면 swap
		}
	}
};
priority_queue<p,vector<p>,comp>pq;

int N, K;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	string S;
	string ans;
	cin >> S;
	for (int i = 0; i < K; i++) {
		int n = S[i] - '0';
		pq.push({ n,i }); //숫자와 position
	}
	int lastIdx=-1;
	for (int i = K ; i < N; i++) {
		int n = S[i] - '0';
		pq.push({ n,i });
		while (!pq.empty()) {
			int num = pq.top().first;
			int idx = pq.top().second;
			pq.pop();
			if (idx < lastIdx)continue;
			else {
				ans += to_string(num);
				lastIdx = idx;
				break;
			}
		}

		
		
	}

	cout << ans << '\n';
	return 0;

}
