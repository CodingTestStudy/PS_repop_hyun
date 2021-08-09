#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;
int K;
struct suffix
{
	int index;
	char* suff;
};
struct suffix suffixes[401];
string exSuffix[401];
int cmp(struct suffix a, struct suffix b)
{
	return strcmp(a.suff, b.suff) < 0 ? 1 : 0;
}


int* buildSuffixArray(char* txt,int n)
{

	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].suff = (txt + i);
		exSuffix[i] = (txt + i);
	}

	sort(suffixes, suffixes + n, cmp);

	
	int* suffixArr = new int[n];
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;


	return  suffixArr;
}


void solve(int test) {

	cin >> K;
	char txt[401];
	cin >> txt;
	int n = strlen(txt);
	int* arr = buildSuffixArray(txt, n);
	
	cout << "#" << test << " " << exSuffix[arr[K - 1]] << '\n';
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solve(test_case);

	}
	return 0;

}
