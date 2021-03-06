//백준 1406 editor
#include <iostream>
#include <list>
#include <string>
using namespace std;
int M;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	list<char> L;
	list<char>::iterator it;
	string in;
	char cmd, some;

	cin >> in;
	cin >> M;

	for (char s : in) {
		L.push_back(s);
	}
	it = L.end();
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 'P') {
			cin >> some;
			it = L.insert(it, some);
			it++;
		}
		else {
			if (cmd == 'L') {
				
				if (it == L.begin()) {
					it = L.begin();
				}
				else --it;

			}

			if(cmd == 'D') {
				
				if (it == L.end()) {
					it = L.end();
				}
				else it++;
			}
			if (cmd == 'B') {
				if (it == L.begin()) {
					it = L.begin();
				}
				else {
					--it;
					it = L.erase(it);
				}

			}

		}


	}

	for (char s : L) {
		cout << s;
	}
	return 0;

}

