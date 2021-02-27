//백준 4354 power string
#include <iostream>
#include <string.h>
using namespace std;
int fail[1'000'002];
void getFail(string& input, int size) {

	for (int i = 1, j = 0; i < size; i++) {

		while (j > 0 && input[i] != input[j])j = fail[j - 1];
		if (input[i] == input[j])fail[i] = ++j;
	}
}

int solve(int N) {

	int ret = 0;
	int Q = N - fail[N - 1];
	
	//그러한 n는 없음, 즉 1
	if (N % Q != 0)return 1;
	else return N / Q;
	

	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	while (1) {
		memset(fail, 0, sizeof(fail));
		string input;
		cin >> input;
		if (input == ".")break;
	
		getFail(input, input.length());
		cout << solve(input.length()) << '\n';
		
		
	}
	
	return 0;

}