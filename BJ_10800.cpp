//백준 10800 컬러볼
#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct {
	int size;
	int color;
	int id;
}info;
bool cmp(const info& a, const info& b) {//사이즈 별로 정렬됨
	if (a.size == b.size) return a.color < b.color;
	return  a.size < b.size;
}
int N;
info arr[200001];
int ans[200001];
int c[200001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(c, 0, sizeof(c));
	memset(ans, 0, sizeof(ans));
	cin >> N;
	info in;
	int color; int size;
	for (int i = 1; i <= N; i++) {
		cin >> color >> size;
		in.id = i;
		in.color = color;
		in.size = size;
		arr[i] = in;
	}
	info init;
	init.size = 0;
	init.color = 0; //아무 색도 아님
	arr[0] = init;
	sort(arr, arr + N + 1, cmp); //사이즈 별로 정렬됨
	//사이즈별로 정렬되어있음, 지나온 사이즈들을 누적한 값에서 누적된 해당 색깔의 사이즈를 뺌
	int sumSize = 0; 
	int redunCnt = 0;
	int j = 0;
	for (int i = 1; i <= N; i++) {
		
		while (arr[j].size < arr[i].size) {
			sumSize += arr[j].size;
			c[arr[j].color] += arr[j].size;
			j++;
		}
	
		ans[arr[i].id] = sumSize - c[arr[i].color];
	}


	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}