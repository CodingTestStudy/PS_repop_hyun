//백준 2457번 공주님의 정원

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v;
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	int sM,sD, eM,eD;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> sM >> sD >> eM >> eD;
		start = sM * 100 + sD; 
		end = eM * 100 + eD;
		pair<int, int>d = make_pair(start, end);
		v.push_back(d);
	}

	sort(v.begin(), v.end());

	int standard = 301; int endStandard = 301;
	int ret = 0;
	for (int i = 0; i < v.size(); ) {
		bool isUpdated = false;
		while (v[i].first <= standard) {
			
			if (endStandard < v[i].second) {
				endStandard = v[i].second;
				isUpdated = true; //업데이트 됨, 즉 넣을게 있다.
			}
			
			
			i++;
			if (i == v.size())break;
		}
		if (!isUpdated) {
	
			cout << 0 << '\n';
			return 0;
		}
		ret++;
		standard = endStandard;
		if (endStandard >= 1201)break;
	}

	if (endStandard >= 1201) cout << ret << '\n';
	else cout << 0 << '\n';
	return 0;

}