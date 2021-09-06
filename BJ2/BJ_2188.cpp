#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 200
int N,M;

vector<int> adj[MAX+2];
int occupy[MAX+2];
bool visited[MAX+2];
bool dfs(int here){

	visited[here]= true; //한번의 사이클 
	
	for(int i = 0 ; i < adj[here].size() ; i++){
		
		int next = adj[here][i];
		
		if(!occupy[next]|| (!visited[occupy[next]] && dfs(occupy[next]))){
			occupy[next] = here;
			return true;
		}
	}
	
	
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 1; i <= N ; i++){
		int num;
		cin >> num;
		for(int j = 0 ; j < num ; j++){
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
	}
	int ans = 0;
	
	for(int i = 1 ; i <= N ; i++){
		memset(visited,false,sizeof(visited));
		if(dfs(i))ans++;	
	
	}
	
	cout << ans << '\n';
	return 0;
	
}