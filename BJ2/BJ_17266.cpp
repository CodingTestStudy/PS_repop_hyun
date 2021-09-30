#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N, M;
int light[100000 + 1];

bool check(int cover) {

	if (light[0] - cover > 0)return false;
	
	else {

		int right = light[0] + cover;

		for (int i = 1; i < M; i++) {

			if (light[i] - cover > right) {

				return false;
			}
			
			else {
				right = light[i] + cover;
			}
		}

		if (right < N) {
			return false;
		}
		
		return true;
		

	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> light[i];
	}
	int lo = 0;
	int hi = 100000;

	while (lo < hi) {
		int mid = (lo + hi) / 2;

		if (check(mid)) { //되면
			hi = mid;
		}
		else lo = mid + 1;


	}


	cout << lo << '\n';
	return 0;

}