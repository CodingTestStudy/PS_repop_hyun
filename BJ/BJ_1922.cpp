//백준 1922 네트워크 연결
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int M;
int p[1001]; //부모 배열


struct edge {

	int v1;
	int v2;
	int cost;
	edge(int v11, int v22, int cc) :v1(v11), v2(v22), cost(cc){}
	bool operator < (const edge& e)const {
		return cost < e.cost; // cost로 오름차순 정리
	}
};

int find(int a) {
	if (p[a] < 0) return a;
	
	p[a] = find(p[a]);
	return p[a];
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false ; //이미 집합임 합칠 수 없음
	
	p[b] = a;
	return true; //merge 성공
}
int main() {
	memset(p, -1, sizeof(p));
	vector<edge> e;
	cin >> N >> M;
	int n1, n2,cost;

	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2 >> cost;
		e.push_back(edge(n1, n2, cost));
	}

	sort(e.begin(), e.end()); //간선 cost에 따라 오름차순 정렬
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < e.size(); i++) {
		if (merge(e[i].v1, e[i].v2)) {
			cnt++;
			ret += e[i].cost;

			if (cnt == N - 1)break;
		}
	
	}
	

	cout << ret << '\n';
	return 0;

}