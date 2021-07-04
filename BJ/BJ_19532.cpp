#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int a, b, c, d, e, f;
int x, y;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c >> d >> e >> f;
	
	x = (e * c - b * f) / (a * e - b * d);
	y = (a*f-d*c)/ (a * e - b * d);

	cout << x << " " << y;
	return 0;

}