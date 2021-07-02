//백준 19541 
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N, M;
bool infected[100000 + 1];
bool ans[100000 + 1];
bool simul[100000 + 1];
vector<int> m[100000 + 1];

bool isSame() {

	//도출된 정답으로 다시 시뮬레이션하여 원래 결과와 같은지 확인
	for (int i = 1; i <= N; i++) {
		if (simul[i] != infected[i]) return false;
	}

	return true;

}

void makeOne(int i) {
	for (int s : m[i]) {
		simul[s] = 1;
	}

}

void makeZero(int i) {
	
	for (int s : m[i]) {
		ans[s] = 0;
	}

}
void solve() {


	//역방
	for (int i = M - 1; i >= 0; i--) {
		for (int s : m[i]) {
			if (ans[s] == 0) {
				makeZero(i); //i번째 모임 ans simul 모두 0으로
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		simul[i] = ans[i];
	}

	//순방
	for (int i = 0; i < M; i++) {
		for (int s : m[i]) {
			if (simul[s] == 1) {
				makeOne(i); //i번째 모임 simul 모두 1로
				break;
			}
		}

	}

	
	if (!isSame())cout << "NO\n";
	else {
		cout << "YES\n";
		
		for (int i = 1; i <= N; i++) {
			cout << ans[i] << " ";
		}


	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int k;
	int inn;
	for (int i = 0; i < M; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> inn;
			m[i].push_back(inn);
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> inn;
		infected[i] = inn;
		ans[i] = infected[i];
		simul[i] = infected[i];
	}



	solve();
	return 0;

}




