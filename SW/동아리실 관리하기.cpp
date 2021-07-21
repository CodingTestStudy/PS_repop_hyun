#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int N;
long long ans = 0;
int must[10005];
long long dp[10005][15];

void func(int day) {
		bool visited[16][16];
		memset(visited, false, sizeof(visited));
		for (int b = 0; b <= 15; b++) {
			unsigned int cur = must[day] | b;
			if (day == 1) {
				dp[day][cur] = 1;

			}
			else {
				for (int j = 0; j <= 15; j++) {
					if ((cur & j) == 0)continue; //겹치는게 하나도 없으면 안됨

					if (!visited[cur][j]) {
						visited[cur][j] = true;
						dp[day][cur] = (dp[day][cur]+ dp[day - 1][j]) % 1000000007;
					}

				}
			}

		}
}
void make_hash(char c,int cnt) {
	int num = (c - 'A');
	must[cnt] = 1 << num;
	if (cnt == 1)must[cnt] = must[cnt] | 1; //첫째날 A필수
}
void solve(int t, string input) {
	memset(dp, 0, sizeof(dp));
	memset(must, 0, sizeof(must));
	ans = 0;
	N = input.length();
	for (int i = 0; i < input.length(); i++) {
		make_hash(input[i], i + 1);
	}
	for (int i = 1; i <= N; i++) {
		func(i);
	}

	for (int i = 1; i <= 15; i++) {
		ans = (ans + dp[N][i]) % 1000000007;
	}

	cout << "#" << t << " " << ans << '\n';
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string input;
		cin >> input;
		solve(test_case, input);

	}
	return 0;
}