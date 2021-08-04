#include<iostream>
#include <queue>

using namespace std;
typedef long long ll;


priority_queue<int> maxQ;
priority_queue<int,vector<int>,greater<int>>minQ;
ll ans;
int N;
void init() {
	while (!maxQ.empty())maxQ.pop();
	while (!minQ.empty())minQ.pop();
	ans = 0;
}

void findMid(int x,int y) {
	int min, max;
	if (x > y) {
		max = x;
		min = y;
	}
	else {
		max = y;
		min = x;
	}
	
	maxQ.push(min);
	minQ.push(max);
	
	if (maxQ.top() > minQ.top()) {
		int maxVal = maxQ.top(); maxQ.pop();
		int minVal = minQ.top(); minQ.pop();
		minQ.push(maxVal);
		maxQ.push(minVal);
		
	}
		

	ans = (ans + maxQ.top()) % 20171109;

}
int solve() {
	init();
	ll a;
	cin >> N >> a;
	maxQ.push(a);
	
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		findMid(x,y);
	}

	return ans % 20171109;
	
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << solve() << '\n';

	}
	return 0;
}