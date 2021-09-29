#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
int N, P;
int W, L, G;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	cin >> W >> L >> G;
	
	for (int i = 0; i < P; i++) {
		string name;
		string w;
		cin >> name >> w;
		if (w == "W") {
			m[name] = 1;
		}
		else if (w == "L") {
			m[name] = 0;
		}

		
	}

	int score = 0;
	
	for (int i = 0; i < N; i++) {
		string who;
		cin >> who;
		
		auto f = m.find(who);
		if (f != m.end()) {
			
			if (f->second == 1) {
				score += W;
			}
			else if (f->second == 0) {
				score -= L;
			}
			

			if (score < 0) {
				score = 0;
			}
			else if (score >= G) {
				cout << "I AM NOT IRONMAN!!\n";
				return 0;
			}

		}
		else {
			score -= L;

			if (score < 0) {
				score = 0;
			}
		}

	}

	cout << "I AM IRONMAN!!\n";
	return 0;

}