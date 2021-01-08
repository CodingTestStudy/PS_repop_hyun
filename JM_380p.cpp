//종만북 380p 문자열 합치기(STRJOIN)
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[102];

void minCost(priority_queue<int, vector<int>, greater<int>>& q,int size) {

	int ret = 0;
	while (q.size() > 1) {
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		int sum = a + b;
		q.push(sum);
		ret += sum;
	
	}
	
	cout << ret << '\n';
}
int main() {
	
	int C;
	int n;
	cin >> C;
	
	for (int i = 0; i < C; i++) {
		priority_queue<int, vector<int>, greater<int>> q;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			q.push(arr[j]);
		}
		minCost(q,n);
	}
	
	return 0;
}