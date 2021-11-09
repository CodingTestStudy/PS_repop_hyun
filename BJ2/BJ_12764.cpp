#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAXN 100000
int N;
using P = pair<int, int>;
class comp {

public:
	bool operator()(const P& a, const P& b) {
		return a.first > b.first;
	}

};
int ans[MAXN+2];
vector<P>inn;
priority_queue<P, vector<P>, comp>pq; //<종료시간,자리번호>
set<int>n_set;//<자리번호,cnt>
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p, q;
		cin >> p >> q;
		inn.push_back({ p,q });
	}

	sort(inn.begin(), inn.end());
	int num = 1; //자리번호
	pq.push({ inn[0].second,num });
	ans[num]++;
	for (int i = 1; i < inn.size(); i++) {
	
		while (!pq.empty()) {

			if (pq.top().first < inn[i].first) {
				P t = pq.top();
				pq.pop();
				n_set.insert(t.second);
		
			}
			else break;
		}
		
		if (n_set.empty()) { //새로 자리 할당
			num++;
			pq.push({ inn[i].second,num});
			ans[num]++;
		}
		else { //해당 자리 차지
			auto f = n_set.begin();
			int next_number = *f;
			n_set.erase(f);
			pq.push({ inn[i].second,next_number });
			ans[next_number]++;
		}
		
		
	}
	
	cout << num  << '\n';
	for (int i = 1; i <= num; i++) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}