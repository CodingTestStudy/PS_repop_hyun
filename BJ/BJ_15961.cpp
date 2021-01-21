// 백준 15961 회전초밥
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;

map<int,int> color;
map<int, int>:: iterator it;
int arr[3'000'001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, d, k, c;

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int s = 0; int e = 0;
	int start, end; //루프 그만둘 시점 저장
	int ret = 0;
	while (k-- > 1) { //k 개 만큼 보기
		it = color.find(arr[e]);
		if (it != color.end())it->second++;
		else color.insert({ arr[e] ,1});
		e = (e + 1) % N;
	}
	it = color.find(arr[e]);
	if (it != color.end())it->second++;
	else color.insert({ arr[e] ,1 });
	start = s; //시작 
	end = e; //시작

	while (1) {
		/*cout << "\n현재 set 목록 \n";
		for (it = color.begin(); it != color.end(); it++) {
			cout << it->first << ' ';
		}
		cout << "\n현재 사이즈:" << color.size() << '\n';*/
		int cnt = 0;
		it = color.find(arr[s % N]);
		if (it != color.end()) {
			if (it->second == 1)color.erase(it);
			else (it->second)--;
			
		}
		e = (e + 1) % N;
		s = (s + 1) % N;
	
		it = color.find(arr[e % N]);
		if (it != color.end()) {
			(it->second)++;
		}
		else color.insert({arr[e % N],1});

		it = color.find(c); //쿠폰 메뉴가 이미 있는지
		if (it == color.end()) { //없다면
			cnt++;
		}
		cnt += color.size();
		ret = max(ret, cnt);
		if (start == s && end == e)break;
	}
	cout << ret << '\n';
	return 0;
}