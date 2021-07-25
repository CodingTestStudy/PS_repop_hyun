//재채점에 의하여 다시 품
#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;
int F, S, G, U, D;

bool check[2000005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(check, 0, sizeof(check));
	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> q;

	q.push({ S,0 });
	check[S] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == G) {
			cout << cnt << '\n';
			return 0;
		}
	

		int upRet = num + U;
		int downRet = num - D;

		if (upRet <= F) {
			if (!check[upRet]) {
				check[upRet] = 1;
				q.push({ upRet,cnt + 1 });
			}
		}

		if (downRet > 0) {
			if (!check[downRet]) {
				check[downRet] = 1;
				q.push({ downRet,cnt + 1 });
			}
		}
	}

	cout << "use the stairs\n";
	
	return 0;

}