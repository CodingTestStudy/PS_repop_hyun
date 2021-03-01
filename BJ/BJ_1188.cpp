//백준 1188번  음식 평론가
#include <iostream>
using namespace std;
int N, M;
//안잘라도 되는경우를 뺀다
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	
	cout << M - gcd(N, M);
	return 0;

}
