#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <regex>
using namespace std;
string sign;
regex re("(100+1+|01)+");
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> sign;
		
	if (regex_match(sign, re)) {
		cout << "SUBMARINE\n";
	}
	else cout << "NOISE\n";
	return 0;

}