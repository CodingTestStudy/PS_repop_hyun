#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
bool check[20];
vector<int> bucket;
int ans[20];

int N;
bool flag;
void dfs(int now) {

	if (now == 2 * N) {
		
	
		for (int i = 0; i < N * 2; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';

		exit(0);
	}

	if (ans[now] != -1) {
		dfs(now + 1);
		return;
	}

	for (int i = 0; i < N; i++) {
		
		if (!check[i] && now + bucket[i] + 1 < 2 * N && ans[now + bucket[i] + 1] == -1) {
			check[i] = 1;
			ans[now] = bucket[i];
			ans[now + bucket[i] + 1] = bucket[i];
			dfs(now + 1);
			ans[now] = -1;
			ans[now + bucket[i] + 1] = -1;
			check[i] = 0;

		}
	}


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		bucket.push_back(x);
	}

	sort(bucket.begin(), bucket.end());
	memset(ans, -1, sizeof(ans));
	dfs(0);
	cout << -1;
	return 0;

}

