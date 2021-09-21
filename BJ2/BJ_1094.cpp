#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int x;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x;
	int ans = 0;
	for (int i = 0; i <= 7; i++) {
		int t = x >> i;
		
		if ((t & 0x1))ans++;
		
	}
	cout << ans << '\n';
	return 0;

}