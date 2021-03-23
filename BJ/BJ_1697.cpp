#include <iostream>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;
int N, K;
bool check[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(check, false, sizeof(check));
	cin >> N >> K;
	
	queue<pair<int, int>> q;
	priority_queue<int,vector<int>,greater<int>> pq;
	q.push({ N,0 });

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == K) {
			pq.push(cnt);
			continue;
		}

		if (num + 1 <= 100000 && !check[num + 1]) {
			check[num + 1] = true;
			q.push({ num + 1,cnt + 1 });
		}
		if (num - 1 >= 0 && !check[num - 1]) {
			check[num - 1] = true;
			q.push({ num - 1,cnt + 1 });
		}
		if (2* num <= 100000 && !check[2 * num]) {
			check[2*num] = true;
			q.push({ 2 * num,cnt + 1 });
		}
	}


	cout << pq.top() << '\n';

	return 0;

}