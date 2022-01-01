#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int N;
int arr[13];
vector<char> oper;
int MIN = 0x3f3f3f3f;
int MAX = -0x3f3f3f3f;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {		
			if (i == 0)oper.push_back('+');
			else if (i == 1)oper.push_back('-');
			else if (i == 2)oper.push_back('*');
			else if (i == 3)oper.push_back('/');
		}
	}
	sort(oper.begin(), oper.end());
	do {
	
		vector<string> S;

		for (int i = 0; i < oper.size(); i++) {

			if (oper[i] == '+' || oper[i] == '-') {

				if (S.size() >= 1) {
					string s(1, oper[i]);
					S.push_back(s);
					S.push_back(to_string(arr[i + 1]));
				}
				else {
					S.push_back(to_string(arr[i]));
					string s(1, oper[i]);
					S.push_back(s);
					S.push_back(to_string(arr[i + 1]));
				}
				
			}
			else {
				
				if (S.size() >= 1) {
					int num = stoi(S[S.size() - 1]);
					S.pop_back();
					int ret = 0;
					if (oper[i] == '*') {

						ret = num * arr[i + 1];
					}
					else if (oper[i] == '/') {
						ret = num / arr[i + 1];

					}

					S.push_back(to_string(ret));
				}
				else {
					int ret = 0;
					if (oper[i] == '*') {

						ret = arr[i] * arr[i + 1];
					}
					else if (oper[i] == '/') {
						ret = arr[i] / arr[i + 1];

					}

					S.push_back(to_string(ret));
				}
			


			}
		
		}


		int Result = stoi(S[0]);

	
		for (int i = 1; i < S.size(); i+=2) {
			
			if (S[i] == "+") {
				
				Result += stoi(S[i + 1]);
			}
			else if(S[i] =="-") {
				Result -= stoi(S[i + 1]);
			}
		}

		MIN = min(MIN, Result);
		MAX = max(MAX, Result);

	

	} while (next_permutation(oper.begin(), oper.end()));
	
	cout << MAX << '\n';
	cout << MIN << '\n';
	
	return 0;

}