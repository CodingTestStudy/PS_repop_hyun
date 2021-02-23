//Codeforces Round #704 (Div. 2)

//A.
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	unsigned long long p,a,b,c;


	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p >> a >> b >> c;

		unsigned long long qA = p / a;
		unsigned long long qB = p / b;
		unsigned long long qC = p / c;
		
		if (p % a == 0|| p % b == 0 || p % c == 0)cout << 0 << '\n';
		else {
			qA++; qB++; qC++;

			cout << min(a * qA - p, min(b * qB - p, c * qC - p)) << '\n';
		}
		
	}
	return 0;

}

*/


//B.
/*
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		priority_queue<pair<int,int>> q;
		vector<int> ret;
		vector<int> arr;
		cin >> n;
		int inn;
		for (int i = 0; i < n; i++) {
			cin >> inn;
			q.push({inn ,i});
			arr.push_back(inn);

		}
		int Exindex = arr.size() ;
		while (ret.size() < n) {
	
			if (Exindex < q.top().second)
			{
				q.pop();
				continue;
			}

			for (int i = q.top().second; i < Exindex; i++) {
				ret.push_back(arr[i]);
			
			}
			Exindex = q.top().second;
			q.pop();

		}

		for (int s : ret) {
			cout << s << ' ';
		}

		cout << '\n';
	}
	return 0;

}*/


//C. 시간초과
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

		int n, m;
		string s;
		string t;
		cin >> n >> m;
		cin >> s;
		cin >> t;
		vector<int> v[200001];
		int k = 0;
		for (int j = 0; j < t.length(); j++) {
			
			for ( ; k < s.length(); k++) {
				if (s[k] == t[j]) {
					v[j].push_back(k);
				}
			}
			k = v[j].front() + 1;
			sort(v[j].begin(), v[j].end(), greater<int>());
			
		}
		
		int ret = -987654321;
		int ee= 987654321;
		for (int j = 0; j < 200001; j++) {
			if (!v[j].size())continue;

			else {
				auto e = v[j].end() - 1;
				
				ret = max(ret, v[j].front() - ee);
				
				ee = *e;
			}
		}


		cout << ret << '\n';

	return 0;

}