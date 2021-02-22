//Codeforces Round #696 (Div. 2)

//A.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
	
		vector<int>a;
		int n;
		cin >> n;
		string b;
		cin >> b;
		char ex = '-1';
		
		if (b[0] == '0') {
			a.push_back(1);
			ex = '1';
		}

		else if (b[0] == '1') {
			a.push_back(1);
			ex = '2';
		}

		if (n > 1) {
			for (int i = 1; i < n; i++) {
				if (b[i] == '0') {

					if (ex == '1') {
						a.push_back(0);
						ex = '0';
					}
					else if (ex == '0' || ex == '2') {
						a.push_back(1);
						ex = '1';
					}


				}
				else  if (b[i] == '1') {
					if (ex == '1' || ex == '0') {
						a.push_back(1);
						ex = '2';
					}
					else if (ex == '2') {
						a.push_back(0);
						ex = '1';
					}

				}
			}
		}

		for (int s : a) {
			cout << s;
		}
		cout << '\n';
	}
	return 0;


//B.

#include <iostream>
#include <string.h>
using namespace std;
bool p[25001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(p, true, sizeof(p));
	for (int i = 2; i <= 25000; i++) {
		
		if (p[i] == false)continue;
		for (int j = i + i; j <= 25000; j += i) {
			p[j] = false;
		}
		
	}
	int t;
	cin >> t;
	int d;
	for (int i = 0; i < t; i++) {
		cin >> d;
		int k = 0;
		for (int j = d + 1; j < 25000; j++) {
			if (p[j] == true) {
				k = j;
				break;
			}
		}
		int n_k = 0;
		for (int j = k+d; j < 25000; j++) {
			if (p[j] == true) {
				n_k = j;
				break;
			}
		}

		cout << k * n_k << '\n';
	}
	return 0;

}