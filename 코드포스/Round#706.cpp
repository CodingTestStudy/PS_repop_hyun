//A. Split it!
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, k;
		string in;
		cin >> n >> k;
		cin >> in;
		
		if (k == 0) { cout << "YES\n"; continue; }

		if(n < 2*k + 1) { cout << "NO\n"; continue; }
	
		else {
			
			string first = in.substr(0, k);
			string second = in;
			reverse(second.begin(), second.end());
			
			if (first == second.substr(0, k)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}


	}
	return 0;

}

/*
B. Max and Mex
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, a;
int getMex(vector<int> &v) {
	
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != i) {
			return i;
		}
	}
}
int cal(int max,int mex) {
	
	if ((max + mex) % 2 == 1) {
		return ((max + mex) / 2) + 1;
	}

	else return (max + mex) / 2;
}
void solve(vector<int>& v) {

	sort(v.begin(), v.end());
	int MAX = v.back();
	int MEX = getMex(v);

	if (MAX < MEX || cal(MAX,MEX) == MEX) {

		cout << n + k << '\n';
	}

	else if (v.end() != find(v.begin(), v.end(), cal(MAX, MEX))) 
	{
		cout << n << '\n';
	}

	else if (v.end() == find(v.begin(), v.end(), cal(MAX, MEX))) {
		if (cal(MAX, MEX) > MEX) {
			cout << n + 1 << '\n';
		}
	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++){
		
		vector<int> v;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		if (k == 0) {
			cout << n << '\n';
			continue;
		}
		solve(v);


	}
	return 0;

}*/
