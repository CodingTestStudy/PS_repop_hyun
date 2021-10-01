#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
int L;
string S;
int fail[1000000 + 1];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	cin >> S;
	memset(fail, 0, sizeof(fail));

	for (int i = 1, j = 0; i < L; i++) {

		while (j > 0 && S[i] != S[j])j = fail[j - 1];
		if(S[i]==S[j])fail[i] = ++j;
		
	}

	cout << L - fail[L - 1] << '\n';
	return 0;

}