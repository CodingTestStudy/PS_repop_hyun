/*
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std; 
vector<pair<int, int>>adj[801];
const int INF = 987654321;
int dist[801];
bool visited[801];
int N, E;
int daik(int start,int end) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	dist[start] = 0;

	q.push({ 0,start }); //dist최소,정점 번호
	while (!q.empty()) {

		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur] == true);

		if (visited[cur] == true)break;
		visited[cur] = true;

		for (pair<int, int> p : adj[cur]) {
			int next = p.first;
			if (dist[next] > dist[cur] + p.second) {
				dist[next] = dist[cur] + p.second;
				q.push({ dist[next],next });

			}
		}


	}
	if (dist[end] == INF)return -987654321;
	return dist[end];

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		
		adj[a - 1].push_back({ b - 1,c });
		adj[b - 1].push_back({ a - 1,c });

	}
	int v1, v2;
	cin >> v1 >> v2;

	int ret = 0;

	

	ret = min(daik(0,v1-1),daik(0,v2-1));
	if (ret < 0) {
		cout << -1 << '\n';
		return 0;
	}


	
	if (ret == daik(0, v1 - 1)) {
		
	
		ret += daik(v2 - 1, N-1);
		if (ret < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}

	else if(ret == daik(0, v2 - 1)){
	
		ret += daik(v1 - 1, N - 1);
		if (ret < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}


	cout << ret << '\n';

	

	return 0;

}

*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
using namespace std;


const int MAX = 800 + 1;

const int INF = 987654321;

 

int N, M;

int trace[MAX]; //경로 파악 위해

vector<pair<int, int>> graph[MAX];

 

vector<int> dijkstra(int start, int vertex)

{

        vector<int> distance(vertex, INF);

        distance[start] = 0;

 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({ 0, start });

 

        while (!pq.empty())

        {

                 int cost = pq.top().first;

                 int cur = pq.top().second;

                 pq.pop();

 

                 if (distance[cur] < cost)

                         continue;

 

                 for (int i = 0; i < graph[cur].size(); i++)

                 {

                         int neighbor = graph[cur][i].first;

                         int neighborDistance = cost + graph[cur][i].second;

 

                         //업데이트할 때마다 trace도 업데이트

                         if (distance[neighbor] > neighborDistance)

                         {

                                 distance[neighbor] = neighborDistance;

                                 trace[neighbor] = cur;

                                 pq.push({ neighborDistance, neighbor });

                         }

                 }

        }

        return distance;

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> N >> M;

 

        N++;

 

        for (int i = 0; i < M; i++)

        {

                 int u, v, w;

                 cin >> u >> v >> w;

 

                 //양방향

                 graph[u].push_back({ v, w });

                 graph[v].push_back({ u, w });

        }

       

        int node1, node2;

        cin >> node1 >> node2;

 

        vector<int> result = dijkstra(1, N);

        vector<int> temp1 = dijkstra(node1, N);

        vector<int> temp2 = dijkstra(node2, N);

        //두 가지 경우

        //1. 1 -> node1 -> node2 -> N

        //2. 1 -> node2 -> node1 -> N

        int answer = min({ result[node1] + temp1[node2] + temp2[N - 1], result[node2] + temp2[node1] + temp1[N - 1] });

        if (answer >= INF || answer < 0)

                 cout << -1 << "\n";

        else

                 cout << answer << "\n";

        return 0;

}



