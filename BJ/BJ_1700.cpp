#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


int N, K;
bool check[101];
int idx[101];
vector<int> v;

vector<int> basket;


void solve() {
	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		
		if (basket.size() != N) {
			//이미 있는거면 넣지않음
			if (find(basket.begin(), basket.end(), v[i]) != basket.end())continue;
			basket.push_back(v[i]);
		}

		else {
			//이미 있는 거라면
			if (find(basket.begin(), basket.end(), v[i]) != basket.end()) {
				continue;
			}
			else {
			
				vector<int>::iterator it;
				memset(check, 0, sizeof(check));
				memset(idx, -1, sizeof(idx));
				vector<int> rev;
				for (int j = i + 1; j < v.size(); j++) {
					it = find(basket.begin(), basket.end(), v[j]);
					
					// 이미 꽂혀 있으면
					if (it != basket.end()) {
						if(!check[v[j]]){
							idx[v[j]] = j;
							check[v[j]] = 1;
						}
					
					}

					else {
						continue;
					}
				}
				
				bool flag = false;
				int last = 0;
				int ex = -1;
			
				for (int s = 0; s < basket.size(); s++) {
					
					if (idx[basket[s]] > 0) {
						if (ex < idx[basket[s]]) {
							last = basket[s];
							
						}
						ex = idx[basket[s]];
						
					}
				}

				for (int s : basket) {
					if (!check[s]) {
						++ret; //하나는 뽑아야함
						it = find(basket.begin(), basket.end(), s);
						basket.erase(it);
						basket.push_back(v[i]);
						flag = true;
						break;

					}
				}

				if (!flag) {
					++ret; //하나는 뽑아야함
					it = find(basket.begin(), basket.end(), last);
					basket.erase(it);
					basket.push_back(v[i]);
				}

				
			}

		}

	}


	cout << ret << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	int inn;
	for (int i = 0; i < K; i++) {
		cin >> inn;
		v.push_back(inn);
	
	}
	

	solve();
	return 0;

}