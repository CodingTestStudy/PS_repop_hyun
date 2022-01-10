#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;
#define MAXN 100000
#define MAXM 100000

using P = pair<int, int>;
int arr[MAXN + 2];
vector<P> ret[MAXN + 2];
int arrRet[MAXN + 2];
int N, M;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ret[a].emplace_back(make_pair(0, c)); //0 은 시작점
		ret[b+1].emplace_back(make_pair(1, c)); // 1 은 끝점

	}
	
	int val = 0;
	for (int i = 1; i <= N; i++) {
		
		if (ret[i].size() > 0) {
			int tmp = 0;
			for (P e : ret[i]) {

				if (e.first == 0) {
					
					tmp += e.second;
					
				}
				else if (e.first == 1) {
					tmp -= e.second;
				}
			

			}
			val += tmp;
			arrRet[i] = val;

		}
		else {
			arrRet[i] = val;
		}


	}


	for (int i = 1; i <= N; i++) {
		
		arr[i] += arrRet[i];
		
		cout << arr[i] << " ";

	}

	cout << '\n';
	
	return 0;

}