
//LCS(Longest Common Subsequence)  응용 알고리즘
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, m;

//같은지 체크하는 함수
bool isSame(char a,char b) {
	
	if (a == b)return true;

	else if (a == 'i' && (b == 'j' || b == 'l' || b == 'i')) {
		
		return true;
	}

	else if (a == 'v' && (b == 'w' || b == 'v')) {
		return true;
	}


	else return false;
}




int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	vector<vector<int>> arr(n+1, vector<int>(m+1, 0));

	for (int i = 1; i <= m; i++) {
		arr[0][i] = i;
	}
	for (int i = 1; i <= n; i++) {
		arr[i][0] = i;
	}

	string ans;
	string realAns;
	cin >> ans;
	cin.ignore();
	cin >> realAns;



	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			
			if (isSame(ans[i - 1], realAns[j - 1])) {
				arr[i][j] = arr[i - 1][j - 1];
			}

			else if(!isSame(ans[i - 1], realAns[j - 1])){
				arr[i][j] = min(arr[i - 1][j - 1] + 1, min(arr[i - 1][j] + 1,arr[i][j-1] + 1));
			}
			
		}
	}


	cout << arr[n][m] << '\n';
	return 0;
}