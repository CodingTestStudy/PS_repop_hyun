#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;
int N,M;
using P = pair<int, int>;
set<int> s;
queue<P> q;
bool visited[500000 + 10];


bool checking(int a) {
	
	if (a == 0) {
		if (s.find(0) != s.end()) {
			return false;
		}
	}

	while (a != 0) {
		int digit = a % 10;
		
		if (s.find(digit) != s.end()) { //고장나서 못누르면
			
			return false;
		}
		
		a /= 10;

	
	}

	return true;
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, false, sizeof(visited));
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}

	q.push({ 100,0 });
	int firstAns;
	while (!q.empty()) {
		P t = q.front();
		q.pop();
		int num = t.first;
		int cnt = t.second;
		if (num == N) {
			firstAns = cnt;
			break;
		}

		if (!visited[num + 1] && num + 1 <= 500000) {
			visited[num + 1] = 1;
			q.push({ num + 1,cnt + 1 });
		}

		if (!visited[num - 1] && num - 1 >= 0) {
			visited[num - 1] = 1;
			q.push({ num -1,cnt + 1 });
		}



	}

	
	int secondAns = 0x3f3f3f3f;
	for (int i = N; i <= 900000; i++) {

		if (checking(i)) {
			secondAns = abs(N - i);
			int click = 0;
			if (i == 0)click++;
			while (i != 0) {
				i /= 10;
				click++;
			}

			secondAns += click;
		
			break;
		}
		
		
	}


	for (int i = N-1; i >= 0; i--) {
		if (checking(i)) {
			int ss = 0x3f3f3f3f;
			ss = abs(N - i);
			int click = 0;
			if (i == 0)click++;
			while (i != 0) {
				i /= 10;
				click++;
			}
			ss += click;

			secondAns = min(secondAns, ss);
			break;
		}

	}


	cout << min(secondAns, firstAns) << '\n';
	return 0;

}