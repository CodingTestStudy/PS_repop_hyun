
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int V, E, P;
vector<pair<int,int>> adj[5000 + 2];
priority_queue<pair<int, int>,vector<pair<int,int>>,less<pair<int, int>> > pq;
int dist[5000 + 2];
int daik(int start, int end) {

	memset(dist, 0x3f3f3f3f, sizeof(dist));

	dist[start] = 0;
	pq.push({ 0,start });
	
	while (!pq.empty()) {
		
		pair<int, int> p = pq.top(); pq.pop();

		int cur = p.second;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nextDist = adj[cur][i].second;

			if (dist[next] > dist[cur] + nextDist) {
				dist[next] = dist[cur] + nextDist;
				pq.push({ nextDist,next });

			}


		}

		

		
	}
	
	return dist[end];


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> P;
	
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});

	}
	
	int save = daik(1,P)+daik(P,V);
	int notSave = daik(1, V);

	if (save <= notSave) {
		cout << "SAVE HIM\n";
	}
	else cout << "GOOD BYE\n";



	

	return 0;

}