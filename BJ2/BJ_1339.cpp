#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;

int conv[26];
bool comp(int& a, int& b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(conv, 0, sizeof(conv));
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string inn;
		cin >> inn;
		int pos = (int)pow(10, inn.length() - 1);
		for (int j = 0; j < inn.length(); j++) {
			conv[inn[j] - 'A'] += pos;
			pos /= 10;
		}


	}

	sort(conv, conv + 26, comp);
	int ans = 0;
	int number = 9;
	for (int i = 0; i < 26; i++) {
		if (number == 0)break;
		ans += conv[i] * number;
		number-=1;
		
	}
	cout << ans << '\n';
	return 0;

}