#include <iostream>
#include <cmath>

using namespace std;


long long c;
int num;
long long ret;
int main() {

	cin >> c;
	ios_base::sync_with_stdio(0); cin.tie(0);
	num = 0;
	ret = 0;
	for(int i = 12; i >= 0; i--) {
		for (int j = 2; j > 0; j--) {
			if (int(c / (j * (pow(7, i))) ) > 0) 
			{
				c = c - (j * (pow(7, i)));
				num = j;
			}
		}
		if (num > 0) {
			ret += pow(3, i) * num;
			num = 0;
		}

	}

	cout << ret << '\n';
	
	return 0;

}