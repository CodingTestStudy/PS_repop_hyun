//기본 세팅
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	return 0;

}


// merge sort구현 연습

int arr[102];
int tmp[102];
void merge(int* arr, int left, int right) {

	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	merge(arr, left, mid);
	merge(arr, mid + 1, right);

	int iL = left;
	int jL = mid + 1;
	int k = left;
	while ((iL <= mid) && jL <= right) {

		if (arr[iL] <= arr[jL]) {
			tmp[k++] = arr[iL++]; //임시 배열에 복사
		}
		else {
			tmp[k++] = arr[jL++];
		}

	}
	//나머지를 합침
	if (iL > mid) {
		for (int i = jL; i <= right; i++) {
			tmp[k++] = arr[i];
		}
	}
	else {
		for (int i = iL; i <= mid; i++) {
			tmp[k++] = arr[i];
		}
	}

	for (int i = left; i <= right; i++) {
		arr[i] = tmp[i]; // 완성된 값 복사
	}

}

//Union-find 구현

//N개의 노드의 부모들이 저장되어있음
int p[N] = {-1,};
int find(int a) {
	if (p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];

}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a; // a가 부모
}


//(구간트리) 세그먼트 트리 :구간 최소 구하는 트리일때
#include <vector>
#include <algorithm>
struct RMQ {
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMin.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
};
int init(const vector<int>& arr, int left, int right, int node) {
	if (left == right) return rangeMin[node] = arr[left];
	int mid = (left + right) / 2;
	int leftMin = init(arr, left, mid, node * 2);
	int rightMin = init(arr, mid + 1, right, node * 2 + 1);
	
	return rangeMin[node] = min(leftMin, rightMin);
}







// 트라이 포인터로 구현 알파벳 26 자일때,
#define ALPHABETS_CNT 26
#define MAXN 100000

struct Trie;
Trie* myAlloc();

struct Trie {
	Trie* _children[ALPHABETS_CNT];

	void add(const char* word) {
		if (*word != 0) {
			if (_children[*word - 'a'] == nullptr)_children[*word - 'a'] = myAlloc();
			_children[*word - 'a']->add(word + 1);

		}
	}


	Trie* get(const char* word) {
		if (*word != 0) {
			if (_children[*word - 'a'] != nullptr)return _children[*word - 'a']->get(word + 1);
			return nullptr;
		}

		return this; //인자로 받은 문자열의 마지막 문자의 트라이 포인터 리턴
	}

	void clear() {
		for (int i = 0; i < ALPHABETS_CNT; i++) {
			_children[i] = nullptr;
		}
	}
};


//문자열관련

void mstrcpy(char dst[], const char src[])
{
	int c = 0;
	while ((dst[c] = src[c]) != 0)
		++c;
}

int mstrlen(const char str[])
{
	int ret = 0;
	while (str[ret])
		++ret;
	return ret;
}

int mstrcmp(const char str1[], const char str2[])
{
	int c = 0;
	while (str1[c] != 0 && str1[c] == str2[c])
		++c;
	return str1[c] - str2[c];
}
