#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 10000

vector<int> path;
vector<int> adj[MAXN + 1];
vector<int> t[MAXN + 1];
int dp[MAXN + 1][2];
int w[MAXN + 1];
int n;

int func(int cur , int check) {

	int& ret = dp[cur][check];
	if (ret != -1)return ret;

	if (t[cur].empty()) {
		if (check)return ret = w[cur];
		else return ret = 0;
	}

	if (check) {
		ret = w[cur];
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			ret += func(next, 0);
		}

		return ret;
	}

	else {
		ret = 0;
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			int r = func(next, 1);
			int l = func(next, 0);
			if (r >= l) { //취하는게 더 크다
				ret += r;
		
			}
			else { 
				ret += l;
			}

		}

		return ret;

	}

}
void findPath(int cur, int check) {
	
	if (check) {

		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			findPath(next, 0);
			
		}
	}
	else {

		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			
			if (dp[next][1] > dp[next][0]) {
				path.push_back(next);
				findPath(next, 1);
			}
			else {
				findPath(next, 0);
			}


		}

	}

}
void make_t(int r, int p) {
	if (p != -1)t[p].push_back(r);

	for (int s : adj[r]) {
		if (s == p)continue;
		make_t(s, r);

	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];

	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}
	make_t(1, -1);
	int ans = 0;
	
	ans = max(func(1, 0),func(1,1));

	if (dp[1][1] > dp[1][0]) {
		findPath(1, 1);
		path.push_back(1);
	}
	else {
		findPath(1, 0);
	}


	sort(path.begin(), path.end());

	cout << ans << '\n';
	for (int p : path) {
		cout << p << " ";
	}

	
	return 0;

}