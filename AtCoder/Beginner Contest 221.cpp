//A
/*
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;
int A, B;
typedef unsigned long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;

	int dif = A - B;
	
	cout << (int)pow(32, dif)<<'\n';


	return 0;

}
*/


//B
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string S, T;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S >> T;

	if (S == T) { cout << "Yes\n"; return 0; }
	bool flag = 0;
	for (int i = 0; i < S.length()-1; i++) {
		
		swap(S[i], S[i + 1]);
		if (S == T) {
			cout << "Yes\n";
			flag = 1;
			break;
		}
		swap(S[i], S[i + 1]);

	}

	if (!flag)cout << "No\n";

	return 0;

}*/

//C
/*
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
string N;
bool visited[15];
vector<char> v;
long long ans = -1;
void permu(int n) {

	if (N.length() == n) {
		string ret = "";
		for (char s : v) {
			ret += s;
		}
		if (ret[0] == '0')return;
		else {
			int idx = 1;
			while (idx < ret.length()) {
				string one = ret.substr(0, idx);
				string two = ret.substr(idx);
				if (two[0] == '0')return;
				else {

					ans = max(ans, stoll(one) * stoll(two));
					
				}
				idx++;
			}
			return;

		}
		
	}

	else {

		for (int i = 0; i < N.length(); i++) {

			if (!visited[i]) {
				visited[i] = 1;
				v.push_back(N[i]);
				permu(n + 1);
				v.pop_back();
				visited[i] = 0;

			}

		}
		
		
	}



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(visited, 0, sizeof(visited));
	cin >> N;
	if (N.length() == 1) {
		cout << N << '\n'; return 0;
	}
	permu(0);

	cout << ans << '\n';
	return 0;

}
*/