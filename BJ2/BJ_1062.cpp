#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
int N, K;
unsigned int st = 0x00;
string ss = "antic";
bool visited[27];
unsigned int voca[51];
int ans = 0;
void comb(int n, int r) {
	
	if (r == 0) {
		unsigned int t = 0x00;
		for (int i = 0; i <= 26; i++) {
			if (visited[i]) {
				t |= (1 << i);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			
			if ((voca[i] & t) == voca[i]) {
				cnt += 1;
			}
		}

		ans = max(ans, cnt);

		return;
	}
	if (n < r)return;

	if (visited[n]) {//antic중 하나이면 선택이 아님
		comb(n - 1, r);
		
	}
	else {
		visited[n] = 1;
		comb(n - 1, r - 1);
		visited[n] = 0;
		comb(n - 1, r);
		
	}
	


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, false, sizeof(visited));
	cin >> N >> K;
	
	for (int i = 0;i < ss.length(); i++) {
		
		st |= (1 << (ss[i] - 97));
		visited[(ss[i] - 97)] = true;
	}
	int r = K - 5;

	string inn;
	for (int i = 0; i < N; i++) {
		cin >> inn;
		unsigned int t = st;
		for (int j = 4; j < inn.length() - 4; j++) {

			t|= (1 << (inn[j] - 97));
		}
		
		voca[i] = t;
	}

	if (r < 0)cout << 0 << '\n';
	
	else {
		comb(26, r);
		cout << ans << '\n';
	}
	return 0;

}