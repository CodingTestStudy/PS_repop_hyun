#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 100000
int N, K;
int arr[MAXN + 1];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		
		cin >> arr[i];

	}


	int st = 0;
	int ed = 0;
	int sum = 0;
	for (ed = 0; ed < K; ed++) {
		sum += arr[ed];

	}
	ed -= 1;
	int ans = -0x3f3f3f3f;
	ans = max(ans, sum);
	while (st+K <= N-1&& ed <= N-1) {

		sum -= arr[st++];
		sum += arr[++ed];
		ans = max(ans, sum);

	}
	cout << ans << '\n';
	return 0;

}