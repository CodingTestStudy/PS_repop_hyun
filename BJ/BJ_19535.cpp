#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;
ll N;
vector<int>adj[300000 + 1];

ll Dcnt = 0;
ll Gcnt = 0;

ll comb(ll n) {

	return (n * (n - 1) * (n - 2)) / 6;
}
void solve() {


	for (int i = 1; i <= N; i++) {
		if (adj[i].size() >= 3) {
			Gcnt +=comb(adj[i].size());
		}
		if (adj[i].size() >= 2) {
			
			for (int s : adj[i]) {
				if (adj[s].size() >= 2) {
					Dcnt += (ll)((adj[i].size() - 1) * (adj[s].size() - 1));
				}
			}

		}
	
	}
	Dcnt /= 2;
	Gcnt *= 3;
	if (Gcnt > Dcnt) {
		cout << "G\n";
	}

	else if (Gcnt < Dcnt) {
		cout << "D\n";
	}

	else cout << "DUDUDUNGA\n";


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	solve();

	return 0;

}


