//백준 1043 거짓말
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N, M;
int p[51];

int find(int a) {
	if (p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];

}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a; // a가 부모
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	memset(p, -1, sizeof(p));
	int trustNum;
	int count;
	cin >> N >> M;
	cin >> trustNum;
	int inn;
	vector<int>truth;
	vector<int>parti[50];
	for (int i = 0; i < trustNum; i++) {
		cin >> inn;
		
		truth.push_back(inn);
	}
	
	for (int i = 0; i < M; i++) {
		cin >> count;
		for (int j = 0; j < count; j++) {
			cin >> inn;
			parti[i].push_back(inn);
		}
		
	}



	//각 파티
	for (int i = 0; i < M; i++) {
	
		int A = parti[i][0]; // 대표 노드
		for (int j = 1; j < parti[i].size(); j++) {

			merge(A, parti[i][j]);
		}

	}



	int ans = M;
	for (int i = 0; i < M; i++) {
		int FirstMan = parti[i][0];
		bool isOk = true;
		for (int j = 0; j < truth.size(); j++) {
			if (find(truth[j]) == find(FirstMan)) {
			
				isOk = false;
				break;
			}
		}

		if (!isOk)ans--;

		

	}

	cout << ans << '\n';
	return 0;

}
