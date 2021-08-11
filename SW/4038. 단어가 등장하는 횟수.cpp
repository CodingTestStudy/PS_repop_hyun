#include<iostream>
#include <string>
#include <string.h>
using namespace std;
string B;
string S;
int ans;
int fail[100001];
void input() {
	memset(fail, 0, sizeof(fail));
	cin >> B;
	cin >> S;
	
}
void make_f(int size) {
	int n = size;

	int begin = 1, m = 0;
	while (begin + m < n) {
		if (S[begin + m] == S[m]) {
			m++;
			fail[begin + m - 1] = m;
		}

		else {
			if (m == 0)begin++;
			else {
				begin += (m - fail[m - 1]);
				m = fail[m - 1];

			}
		}
	}

}
void solve(int test) {
	ans = 0;
	input();
	int b_len = B.length();
	int s_len = S.length();
	make_f(s_len);
	if (b_len < s_len)ans = 0;
	else {
		
		int begin = 0; int m = 0;
		while (begin <= b_len - s_len) {
			
			if (m < s_len && B[begin + m] == S[m]) {
				m++;
				if (m == s_len)ans++;// 찾음
			}

			else {
				if (m == 0)begin++;

				else {
					begin += (m - fail[m - 1]);
					m = fail[m - 1];
				}
			}
		}
		

	}
	cout << "#" << test << " " << ans << '\n';
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solve(test_case);
		
	}
	return 0;
}