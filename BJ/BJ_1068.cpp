//백준 1068 트리
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N;
int del;
int R;
int ans = 0;
bool flag = 0;
vector<int> adj[51];
int trav(int st) {


	int ret = 0;
	if (adj[st].empty()) { 
		return 1;
	}

	for (int s : adj[st]) {

		ret += trav(s);
		
	}

	return ret;
}
void check(int st) {
	if (adj[st].size() == 1) {
		if (adj[st][0] == del) {
		
			flag = 1;
			return;
		}
	}

	for (int s : adj[st]) {
		
		check(s);

	}

	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	int inn;
	for (int i = 0; i < N; i++) {
		cin >> inn;
		if (inn == -1) {
			R = i;
			continue;
		}
		adj[inn].push_back(i);
	
	}
	cin >> del;

	ans = trav(R) - trav(del);

	check(R);
	if (flag)cout << ans + 1 << '\n';
	else cout << ans << '\n';
	

	
	return 0;

}
