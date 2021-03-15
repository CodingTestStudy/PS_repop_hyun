//백준 16500 문자열판별

#include <iostream>
#include <string>
using namespace std;
string A[101];
string S;
int N;
int dp[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> S;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	dp[S.length()] = 1;


	for (int i = S.length() - 1; i >= 0; i--) {

		for (int j = 0; j < N; j++) {
			if (i == S.find(A[j], i) && dp[i + A[j].length()] == 1) {
				dp[i] = 1;
				break;
			}
		}

	}

	cout << dp[0] << '\n';
	return 0;

}