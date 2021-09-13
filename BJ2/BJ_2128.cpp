#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N, D, K;
vector<int> user[1001];
int ans = -1;
bool visited[16];

int Counting() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < user[i].size(); j++) {
			if (!visited[user[i][j]]) {
				flag = false;
				break;
			}
			
		}
		if (!flag)continue;
		else if (flag) cnt += 1; //해당 학생 풀 수 있음

	}

	return cnt;
}
void comb(int n, int r) { //문제 고르기
	if (r == 0) {
		ans = max(ans, Counting());
		return;
	}
	if (n < r)return;
	else {
		visited[n] = true;
		comb(n - 1, r - 1);
		visited[n] = false;
		comb(n - 1, r);

	}
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, false, sizeof(visited));

	cin >> N >> D >> K;

	for (int i = 0; i < N; i++) {
		int cnt;
		cin >> cnt;
		int w = 0;
		for (int j = 0; j < cnt; j++) {
			int inn;
			cin >> inn;
			user[i].push_back(inn);
		
		}
	
	}
	comb(D, K);


	

	cout << ans << '\n';
	return 0;

}
