
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef pair<int, int> P;
int T;
int N, M;
vector<P>v;
vector<int>book;
bool comp(const P& a, const P& b) {

	if (a.second ==  b.second) {
		return a.first > b.first;
	}

	else return a.second < b.second;


}
void solve() {
	book.clear(); v.clear();
	cin >> N >> M;

	for (int i = 1; i <= N; i++)book.push_back(i);

	for (int i = 0; i < M; i++) {
		int lo, hi;
		cin >> lo >> hi;
		
		v.push_back({ lo,hi });


	}

	sort(v.begin(), v.end(), comp);


	int ans = 0;
	
	for (const P& e : v) {
		
		auto f = lower_bound(book.begin(), book.end(), e.first);
		if (f == book.end())continue;
		if (*f <= e.second) {
			book.erase(f);
			ans += 1;
		}

	}

	cout << ans << '\n';

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {

		solve();

	}
	return 0;

}