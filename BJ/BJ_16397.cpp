#include <iostream>
#include <utility>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;
int N, T, G;
queue<pair<int, int>> q;
priority_queue<int,vector<int>,greater<int>>pq;
const int MAX = 99999;
bool isThere[1'000'000];
int check(int& a) { //자릿수 반환
	int cnt = 0;
	for (int i = 10; i <= 1000000; i *= 10 ) {
		++cnt;
		if (a / i == 0)break;
	}

	return cnt;
}
int B(int n) {
	

	int ret = 2 * n;
	if (ret > MAX)return -1;
	int c = check(ret);
	
	ret = ret - int(pow(10, c - 1));
	return ret;


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(isThere, 0, sizeof(isThere));
	cin >> N >> T >> G;

	q.push({ N , 0 });
	isThere[N] = 1;
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt > T)continue;
		if (num == G) {
			pq.push(cnt);
			continue;
		}
		
		int retA = num  +  1;
		int retB = B(num);
		if (retB < 0) {
			if (!isThere[retA]) {
			
				isThere[retA] = 1;
				q.push({ retA,cnt + 1 });
			}
		}
		else{
			if (!isThere[retA]) {
			
				isThere[retA] = 1;
				q.push({ retA,cnt + 1 });
			}
			if (!isThere[retB]) {
	
				isThere[retB] = 1;
				q.push({ retB,cnt + 1 });
			}
		}
	
		
		
		
	}


	if (pq.empty()) cout << "ANG\n";
	else cout << pq.top() << '\n';


	return 0;

}
