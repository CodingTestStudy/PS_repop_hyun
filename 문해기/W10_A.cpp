
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
int M;
int score[30];
int dp[1 << 23][26]; // 경우의수 에서 필요한 알파벳의 갯수
bool isOk[1<<23];
int alphabet[30][26]; // row 번째 단어 만드는데에 필요한 알파벳수
int getScore[1 << 23]; //경우에 수에 따른 점수
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(isOk, true, sizeof(isOk));
	memset(dp, -1, sizeof(dp));
	memset(alphabet, 0, sizeof(alphabet));

	for (int i = 0; i < 26; i++) {
		cin >> dp[0][i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		string word;
		cin >> word;
		cin >> score[i];
		for (int j = 0; j < word.length(); j++) {
			alphabet[i][word[j] - 'a'] += 1;
		}

	}

	int ans = -1;
	for (int i = 0; i < M; i++) {

		int status = 1 << i;
		for (int j = 0; j < status; j++) {
			if (isOk[j] == false)continue;
			bool flag = false;

			for (int k = 0; k < 26; k++) {
				if (dp[j][k] < alphabet[i][k]) {
					flag = true;
					break;
				}
			}

			if (flag) {
				isOk[j|status] = false;
				continue;
			}

			for (int k = 0; k < 26; k++)
			{
				dp[j | status][k] = dp[j][k] - alphabet[i][k];
			}

			getScore[j | status] = getScore[j] + score[i];
		
			ans = max(ans, getScore[j | status]);
		}
		

	}


	cout << ans << '\n';
	return 0;

}