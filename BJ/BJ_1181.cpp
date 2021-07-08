//백준 1181
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
typedef pair<int, string> P;
priority_queue<P,vector<P>,greater<>> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		pq.push({ input.length(),input });

	}


	while (!pq.empty()) {

		int size = pq.top().first;
		string t = pq.top().second;
		vector<string>v;
		v.push_back(t);
		pq.pop();
		while (pq.size() > 0 && pq.top().first == size) {
			t = pq.top().second;
			v.push_back(t);
			pq.pop();
			
		}


		v.erase(unique(v.begin(), v.end()), v.end());
		sort(v.begin(), v.end());

		for (string s : v) {
			cout << s << '\n';
		}

	}
	return 0;

}
