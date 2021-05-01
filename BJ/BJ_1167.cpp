//백준 1167 트리의 지름
#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int V;
int ans = 0;
typedef pair<int, int> p;

vector<p> t[100000 + 1];
bool visited[100000 + 1];

int maxNode;
int maxDist= -1;

void DFS(int here, int dist) {
	
	if (dist > maxDist) {
		maxDist = dist;
		maxNode = here;
	}

	visited[here] = true;

	for (int i = 0; i < t[here].size(); i++) {
		int next = t[here][i].first;
		int n_d = t[here][i].second;
		if(!visited[next])DFS(next, dist + n_d);
		
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V;
	int node;
	for (int i = 0; i < V; i++) {
		int dist;
		int to;
		cin >> node;
		while (1) {
			cin >> to;
			if (to == -1)break;
			else {
				cin >> dist;
				t[node].push_back({ to,dist });
				
				
			}

		}
	}

	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	DFS(maxNode, 0);
	

	cout << maxDist << '\n';
}