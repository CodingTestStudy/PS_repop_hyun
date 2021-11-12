
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#define MAXN 1000000000
#define rep(i,n) for(int i = 0 ; i < n ; ++i)

using namespace std;
using P = pair<int, int>;
bool visited[1000 + 2];
int N, K;
vector<P> v;
bool comp(P & a, P & b) {
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	memset(visited, false, sizeof(visited));
	rep(i, K) {
		int a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);
		v.push_back({ a, b });
	}
	
	sort(v.begin(), v.end(), comp);
	int ans = 0;
	rep(i, K) {
		if (!visited[i]) {
			visited[i] = true;
			ans++;
			for (int j = i + 1; j < K; j++) {
				if (v[j].first < v[i].second) {
					visited[j] = true;
				}
				
			}

		}
	}
	cout << ans + 1 << '\n';
	return 0;

}