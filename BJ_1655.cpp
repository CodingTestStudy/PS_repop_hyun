//백준 1655 가운데를 말해요
/*
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> q; //최소 힙
priority_queue<int, vector<int>, less<int>> q2; //최대 힙
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		
		if (q2.size() > q.size()) q.push(input);
		else {
			q2.push(input);
		}
	
		if (!q.empty() && !q2.empty()) {
			if (q2.top() > q.top()) { //swap
				int MaxVal = q2.top();
				int minVal = q.top();
				q2.pop();
				q.pop();
				q2.push(minVal);
				q.push(MaxVal);

			}
		}
		
		cout << q2.top() << '\n';
	
	}

	
	return 0;

}*/
