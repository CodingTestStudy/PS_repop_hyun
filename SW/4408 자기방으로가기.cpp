
#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int ans; 
int N;
bool isDone[401];
void solve(int test) {
	memset(isDone, 0, sizeof(isDone));
	ans = 0;
	cin >> N;
	vector<pair<int, int>> v;
	int a, b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a < b)v.push_back({ a,b });
		else v.push_back({ b,a });

		
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (isDone[i])continue;
		int stand = v[i].second;
		for (int j = i+1; j < v.size(); j++) {
			if (isDone[j])continue;
			
			if ((stand & 1) != 0) { // 홀수
				if (v[j].first > stand + 1) {
					stand = v[j].second;
					isDone[j] = true;
				}
			}
			//짝수
			else {
				if (v[j].first > stand) {
					stand = v[j].second;
					isDone[j] = true;
				}
			}
		
		}
	
		ans++;
	}
	cout << "#" << test << " " << ans << '\n';
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;


	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		solve(test_case);

	}
	return 0;
}