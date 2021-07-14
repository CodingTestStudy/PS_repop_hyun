#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int n, m;
vector<int>v;
vector<int>ret;
void combi(int idx,int cnt) {

	if (cnt == m) {
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		
		ret.push_back(v[i]);
		combi(i + 1, cnt + 1);
		ret.pop_back();

	}
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	combi(0,0);
	
	return 0;

}
