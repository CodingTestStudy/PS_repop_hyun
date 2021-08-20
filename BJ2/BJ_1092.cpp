#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N, M;
vector<int> crane;
vector<int> box;


bool comp(int& a, int& b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int inn;
		cin >> inn;
		crane.push_back(inn);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int inn;
		cin >> inn;
		box.push_back(inn);
	}
	int ans = 0;
	sort(crane.begin(),crane.end(),comp);
	sort(box.begin(), box.end(),comp);
	if (box[0] > crane[0])cout << -1 << '\n';
	else {
		while (!box.empty()) {
			ans++;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < box.size(); j++) {
					if (crane[i] >= box[j]) {
						box.erase(box.begin() + j);
						break;
					}
				}
			}

		}


		cout << ans << '\n';
	}
		

	return 0;

}