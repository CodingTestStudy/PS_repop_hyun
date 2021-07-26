#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <utility>
 using namespace std;
 int N;
 typedef pair<int, int> P;
 string name[100001];
 bool comp(P& a, P& b) {
	 if (a.first == b.first) {
		 return a.second < b.second;
	 }
	 else return a.first < b.first;
 }
 vector<P> v;
 int main() {
	 ios_base::sync_with_stdio(0); cin.tie(0);
	 cin >> N;
	 int age;
	 string inn;
	 for (int i = 0; i < N; i++) {
		 cin >> age;
		 cin >> inn;
		 name[i] = inn;
		 v.push_back({ age,i });
	 }

	 sort(v.begin(), v.end(), comp);

	 for (P s : v) {
		 cout << s.first << " " << name[s.second] << '\n';

	 }
	 return 0;

 }
