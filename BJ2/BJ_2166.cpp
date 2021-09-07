#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;
int N;
typedef pair<int, int> P;
vector<P> v;
double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		double a, b;
		cin >> a >> b;
		v.push_back({ a, b });

	}
	//기준
	P std = v[0];
	double ans = 0;
	for (int i = 1; i < v.size()-1; i++) {

		ans += 0.5*ccw(std.first,std.second,v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);

	}

	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << '\n';

	
	return 0;

}
