#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N, M;
bool checked[10];
vector<int> ret;
void dfs(int m) {

	if (m == M) {
	
		for (int e : ret) {
			cout << e << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {

		if (!checked[i]) {

			checked[i] = 1;
			ret.emplace_back(i);
			dfs(m + 1);
			ret.pop_back();
			checked[i] = 0;

		}

	}


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(checked, false, sizeof(checked));
	

	dfs(0);


	return 0;

}