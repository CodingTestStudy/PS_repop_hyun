#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;
int F, S, G, U, D;

bool check[1000001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(check, 0, sizeof(check));
	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> q;
	priority_queue<int,vector<int>,greater<int>> pq;

	q.push({ S,0 });
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == G) {
			pq.push(cnt);
			continue;
		}
		if (cnt > F)continue;


		int upRet = num + U;
		int downRet = num - D;

		if (downRet < 0 || upRet > F)continue;

		if (!check[upRet]) {
			check[upRet] = 1;
			q.push({ upRet,cnt + 1 });
		}
		if (!check[downRet]) {
			check[downRet] = 1;
			q.push({ downRet,cnt + 1 });
		}
	}

	if (pq.empty())cout << "use the stairs\n";
	else cout << pq.top() << '\n';
	return 0;

}