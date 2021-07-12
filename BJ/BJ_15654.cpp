#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N, M;
vector<int>v;
vector<int>bas;
bool visited[10] = { false };
int arr[10] = { 0 };
void permu(int cnt) {
	

	if (cnt == M) {
		for (int s = 0; s < M; s++) {
			cout << arr[s] << ' ';
		}
		cout << '\n';
	
		return;
	}


	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = v[i];
			permu(cnt + 1);
			
			visited[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());


	permu(0);

	return 0;

}
