#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int Length;
string ans ="";
void Div(string s, int F, int S) {
	string A, B, C;
	A = "";
	B = "";
	C = "";
	for (int i = 0; i <= F; i++) A = A + s[i];
	for (int i = F + 1; i <= S; i++) B = B + s[i];
	for (int i = S + 1; i < Length; i++) C = C + s[i];
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());

	string tmp = A + B + C;
	if (ans == "")ans = tmp;
	else {
		if (ans > tmp)ans = tmp;
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string inn;
	cin >> inn;
	
	Length = inn.length();


	for (int i = 0; i < Length-1; i++) {
		for (int j = i; j < Length - 1; j++) {
			if (i == j)continue;
			string tmp = inn;
			Div(tmp, i, j);
		}
	}

	cout << ans << '\n';
	return 0;

}