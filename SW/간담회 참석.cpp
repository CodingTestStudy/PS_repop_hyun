#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int N, M, X;
int memPoolCnt;

//pool
struct Node {
	int to;//cost
	int cost; // node
	Node* prev;
};

struct Head {
	Node* data;
};

Node node[1000005];
Head adj[50001]; //[from].to
Head rev[50001];

int distFromX[50000 + 1];
int distToX[50000 + 1];
const int INF = 0x3f3f3f3f;
int ans;
void daik(int st) {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,st });
	distFromX[st] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (distFromX[node] < dist)continue;
		Node* cur = adj[node].data;
		while(cur != nullptr){
			
			int w = cur->to;
			int nextDist = dist + cur->cost;
			if (distFromX[w] > nextDist) {
				distFromX[w] = nextDist;
				pq.push({ -nextDist, w });
			}

			
			cur = cur->prev;
			
		}


	}


}
void daik_rev(int st) {
	priority_queue<pair<int, int>> pq;
	distToX[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (distToX[node] < dist)continue;
		Node* cur = rev[node].data;
		while (cur != nullptr) {
			
			int w = cur->to;
			int nextDist = dist + cur->cost;
			if (distToX[w] > nextDist) {
				distToX[w] = nextDist;
				pq.push({ -nextDist, w });
			}
			cur = cur->prev;
		}

	}

}
void init() {

	ans = 0;
	memPoolCnt = 0;

	//다시 사용한 만큼 초기화
	for (int i = 1; i <= 50000; i++) {
		adj[i].data = 0;
		rev[i].data = 0;
		distFromX[i] = INF;
		distToX[i] = INF;
	}

}
void solve(int test) {
	cin >> N >> M >> X;
	init();
	int s, e, t;

	for (int i = 0; i < M; i++) {
		cin >> s >> e >> t;
		Node* tmp = &node[memPoolCnt++];
		tmp->to = e;
		tmp->cost =t;
		tmp->prev = adj[s].data;
		adj[s].data = tmp;

		Node* rtmp = &node[memPoolCnt++];
		rtmp->to = s;
		rtmp->cost = t;
		rtmp->prev = rev[e].data;
		rev[e].data = rtmp;

	
	}


	daik(X);
	daik_rev(X);



	for (int i = 1; i <= N; i++) {
		if (i == X)continue;
		ans = max(ans, distFromX[i] + distToX[i]);
	}

	cout << "#" << test << " " << ans << '\n';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		solve(test_case);

	}
	return 0;
}