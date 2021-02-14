#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int fail[5001];
int ret = 0;
int N;
int failing(string S) {
	memset(fail, 0, sizeof(fail));
	int i, j;
	j = 0;
	int n = S.length();
	for (int i = 1; i < n; i++) 
	{
		while (j > 0 && S[i] != S[j])j = fail[j - 1];
		if (S[i] == S[j]) {
			fail[i] = ++j;
			ret = max(fail[i], ret);
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string S;
	getline(cin, S, '\n');
	
	N = S.length();


	
	for (int k = 0; k < N; k++) {
		
		
		ret = max(ret,failing(S.substr(k)));
	
	}

	cout << ret << '\n';
	return 0;

}
