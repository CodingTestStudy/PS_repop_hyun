#include<iostream>
using namespace std;
int arr[100002];
int cArr[100002];
int N, K;
void init(int n) {
	for (int i = 0; i < n; i++)
		arr[i] = cArr[i];
}
void solve(int test) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cArr[i] = arr[i];

	}
	int l = 0;
	int r = 1e9;
	int ans =  0;
	while (l < r) {
		int mid = (l + r) / 2;
		int k = K;
		bool isEnd = false;
		init(N);
		for (int i = 0; i < N-1; i++) {
			if (arr[i + 1] - arr[i] >= mid) {
				k -= arr[i + 1] - arr[i] - mid;

				arr[i + 1] -= (arr[i + 1] - arr[i]) - mid;
				if (k < 0) {
					isEnd = true;
					break;
				}
			}
			
			
		}

		for (int i = N - 1; i >= 1; i--) {
			if (arr[i - 1] - arr[i] >= mid) {
				
				k -= arr[i - 1] - arr[i] - mid;
				arr[i - 1] -= arr[i - 1] - arr[i] - mid;
				if (k < 0) {
					isEnd = true;
					break;
				}
			}
		}

		if (isEnd) {
			l = mid + 1;
			ans = l;
		}
		else r = mid;
		
	}




	cout << "#" << test << " " << ans << '\n';
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;

	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		solve(test_case);
	}
	return 0;
}



