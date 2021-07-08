#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n, m;
string dp[101][101]; //nCr 값
string string_add(string n1,  string n2) {
	int sum = 0;
	string ret;


	while (!n1.empty() || !n2.empty() || sum)
	{
		if (!n1.empty())
		{
			sum += n1.back() - '0';
			n1.pop_back();
		}
		if (!n2.empty())
		{
			sum += n2.back() - '0';
			n2.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

string comb(int n, int r) {
	
	if (n == r || r == 0) {
		return "1";
	}
	string& ret = dp[n][r];
	if (ret != "")return ret;

	ret = string_add(comb(n - 1, r - 1), comb(n - 1, r));
	return ret;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < 101; i++) {
		fill(&dp[i][0], &dp[i][100], "");
	}
	cout << comb(n, m) << '\n';
	return 0;

}