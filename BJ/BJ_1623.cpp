#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> t[200001];
int val[200001];
int dp[200001][2];

int DFS(int cur, int parti) {

	int& ret = dp[cur][parti];
	if (ret != -1) {
		return ret;
	}


	if (t[cur].empty()) {
		if (parti == 1) {

			return val[cur];
		}

		else return 0;
	}

	if (parti == 1) {
	
		ret = val[cur];
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			ret += DFS(next, 0);
		}
		
		return ret;

	}

	else if (parti == 0) {
		ret = 0;
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			
			ret += max(DFS(next, 1), DFS(next, 0));
			
		}

		return ret;
	}

}

vector<int> v;
void trav(int cur, int parti) {
	if (parti)v.push_back(cur);
	for (int i = 0; i < t[cur].size(); i++) {
		int next = t[cur][i];
		if (parti)trav(next, 0);
		else trav(next, DFS(next, 0) < DFS(next, 1));
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
	}

	int inn;
	for (int i = 2; i <= N; i++) {
		cin >> inn;
		t[inn].push_back(i);
	}

	
	int boss = DFS(1, 1);

	int noBoss = DFS(1, 0);

	cout << boss << ' ' <<noBoss << '\n';
	//사장있을 때
	trav(1, 1);

	sort(v.begin(), v.end());
	for (int s : v)cout << s << ' ';
	cout << -1 << '\n';
	v.clear();
	//없을 떄,
	trav(1, 0);
	sort(v.begin(), v.end());
	for (int s : v)cout << s << ' ';
	cout << -1 << '\n';
	return 0;

}
