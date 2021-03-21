#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int K;
string N;
queue<string>q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);


	cin >> N >> K;
	q.push(N);

	for (int i = 0; i < K; i++) {
		set<string> s;
		set<string>::iterator it;
		int qsize = q.size();
		
		for (int j = 0; j < qsize; j++) {
			string tmp = q.front();
			q.pop();
			it = s.find(tmp);
			if (it != s.end())continue;
			
			s.insert(tmp);

			for (int l = 0; l < tmp.size()-1; l++) {
				for (int r = l + 1; r < tmp.size(); r++) {
					if (!(l == 0 && tmp[r] == '0')) {
						swap(tmp[l], tmp[r]);
						q.push(tmp);
						swap(tmp[l], tmp[r]);
					}
				}
			}

		}



	}

	string ans = "0";
	while (!q.empty()) {
		ans = max(ans, q.front());
		q.pop();
	}

	if (ans[0] == '0')cout << -1 << '\n';

	else cout << ans << '\n';
	return 0;

}