#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


typedef pair<int, int> P;
queue<P> q;
bool check[100000 + 1];
int ans = 0;
int N, K;
const int INF = 0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(check, 0, sizeof(check));
	cin >> N >> K;
	int countAns = 0;
	int minCount = INF;
	q.push({ N,0 });
	while (!q.empty()){
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		check[num] = 1;

		if (num == K && minCount != INF && minCount == cnt) {
			ans++;
		}

		if (num == K && minCount == INF ) {
			
			minCount = cnt;
			ans++;
		}

		if ( num * 2 <= 100000 && !check[num * 2] ) {
			q.push({ num * 2,cnt + 1 });
		}
	
		if (num + 1 <= 100000 && !check[num + 1] ) {
			q.push({ num + 1,cnt + 1 });
		}
	
		if (0 <= num - 1 && !check[num - 1]) {
			q.push({ num - 1,cnt + 1 });
		}
	



	}

	cout << minCount << '\n' << ans << '\n';
	return 0;

}