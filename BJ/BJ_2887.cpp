#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N;
int p[100000 + 1];
long long ans = 0;

struct block {
	int cost;
	int from;
	int to;

};

struct compare {

	bool operator()(block& a, block& b) {
		return a.cost > b.cost;
	}
};

priority_queue<block,vector<block>,compare> pq;


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


struct coord {
	int num;
	int x;
	int y;
	int z;
};
vector<coord> v;

bool compX(coord& a, coord &b) {
	return a.x < b.x;
}
bool compY(coord& a, coord& b) {
	return a.y < b.y;
}
bool compZ(coord& a, coord& b) {
	return a.z < b.z;
}
void pushing(int m) {

	if (m == 0) {
		for (int i = 0; i < N - 1; i++) {
			block tmp;
			tmp.cost = abs(v[i].x - v[i + 1].x); //비용 계산
			tmp.from = v[i].num;
			tmp.to = v[i + 1].num;
			pq.push(tmp);
		}
	}

	else if (m == 1) {
		for (int i = 0; i < N - 1; i++) {
			block tmp;
			tmp.cost = abs(v[i].y - v[i + 1].y); //비용 계산
			tmp.from = v[i].num;
			tmp.to = v[i + 1].num;
			pq.push(tmp);
		}
	}


	else if (m == 2) {
		for (int i = 0; i < N - 1; i++) {
			block tmp;
			tmp.cost = abs(v[i].z - v[i + 1].z); //비용 계산
			tmp.from = v[i].num;
			tmp.to = v[i + 1].num;
			pq.push(tmp);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(p, -1, sizeof(p));
	cin >> N;
	coord a;
	int x, y, z;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> z;
		a.x = x;
		a.y = y;
		a.z = z;
		a.num = i;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end(), compX);
	pushing(0);

	sort(v.begin(), v.end(), compY);
	pushing(1);

	sort(v.begin(), v.end(), compZ);
	pushing(2);

	int cnt = 0;
	while (!pq.empty()) {
		if (cnt == N - 1)break;
		block t = pq.top();
		pq.pop();
		if (find(t.from) == find(t.to)) {
			continue;
		}

		else {
			merge(t.from, t.to);
			ans += t.cost;
			cnt += 1;
		}

	}

	cout << ans << '\n';
	return 0;

}
