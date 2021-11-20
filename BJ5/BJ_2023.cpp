
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int N;
vector<string>ans;

bool primeCheck(int n) {
	bool flag = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
		
			return false;
		}
	}
	return true;
}
void bfs(string& sum) {

	if (sum.length() == N) { //완성
		
		int retNumber = stoi(sum);
		
		if (primeCheck(retNumber))ans.push_back(sum);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		
		if (i % 2 == 0)continue;

		char curNum = i + 48;
		string prime = sum + curNum;
		if (primeCheck(stoi(prime))) {
			sum += curNum;
			bfs(sum);
			sum.pop_back();
		}
		
	}
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<string> s;
	s.push_back("2"); s.push_back("3"); s.push_back("5"); s.push_back("7");
	
	for (string st : s) {
		string start = st;
		bfs(start);
	}

	for (string e : ans) {
		cout << e << '\n';
	}
	return 0;

}