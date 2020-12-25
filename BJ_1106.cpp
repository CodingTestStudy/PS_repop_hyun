//백준 1106 호텔
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[2001];
int c[21];
int p[21];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	

	memset(dp, -1, sizeof(dp));

	int C;
	int N;
	cin >> C >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> c[i] >> p[i];
	

	}
	
	dp[0] = 0;
	for (int i = 1; i <= 2000; i++) {

		for (int j = 0; j < N; j++) {

			if (dp[i] == -1) {
				if (i / p[j] == 0)dp[i] = c[j];
				else dp[i] = ((i / p[j])) * c[j] + ( i % p[j] != 0 ? c[j] : 0);
				
			}

			else {

				if (i - p[j] >= 0) {
					dp[i] = min(dp[i], dp[i - p[j]] + c[j]);

				}
			}

		}
	}
		
	int ret = 987654321;
	for (int i = C; i <= 2000; i++)
	{
		ret = min(ret, dp[i]);
	}
	cout << ret << '\n';

	return 0;

}