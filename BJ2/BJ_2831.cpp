
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
vector<int>B;
vector<int>G;
bool check(int a, int b) {
	//부호 같으면 true
	
	if (a < 0 && b < 0)return true;
	else if (a > 0 && b > 0)return true;
	else return false;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}
	for (int i = 0; i < N; i++) {
		int g;
		cin >> g;
		G.push_back(g);
	}

	int hi = 0;
	int lo = N - 1;
	
	sort(B.begin(), B.end());
	sort(G.begin(), G.end());
	int ans = 0; 
	while (hi < N && 0 <= lo) {
		
		
		if (check(B[hi], G[lo])) {
			//부호 -로같으면
			if (B[hi] < 0) {
				hi++;
				continue;
			}
			//부호 +로 같으면
			else if (B[hi] > 0) {
				lo--;
				continue;
			}
		
		}
	
		int sum = B[hi] + G[lo];
		if (sum < 0) {
			ans++;
			hi++;
			lo--;

		}
		else {
			lo--;
		}

	}
	cout << ans << '\n';
	return 0;

}