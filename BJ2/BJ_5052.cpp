#include <iostream>

using namespace std;

#define NUMBER_CNT 10
#define MAXN 100001

struct Trie;


Trie* myAlloc();

struct Trie {
	Trie* _children[NUMBER_CNT];
	bool done;
	bool nextExist;
	void add(const char* word) {
		if (*word == '\0') {
			done = true;
		}
		else {
			if (_children[*word - '0'] == nullptr)_children[*word - '0']=myAlloc();
			nextExist = true; //다음이 존재
			_children[*word - '0']->add(word + 1);

		}
	}


	void clear() {//트라이 노드 초기화
		nextExist = false;
		done = false;
		for (int i = 0; i < NUMBER_CNT; i++) {
			_children[i] = nullptr;
		}
	}

	bool isOk() {
	
		if (nextExist && done)return false;
		
		for (int i = 0; i < NUMBER_CNT; i++) {
			if (_children[i] && !_children[i]->isOk()) {
				return false;
			}
		}
		return true; //일관성 달성

	}
};

Trie Node[MAXN];
int nodeCnt = 0;
Trie* myAlloc() {

	Trie* ret = &Node[nodeCnt++];
	ret->clear();
	return ret;

}

int T;
int n;
Trie* root;
void input() {
	nodeCnt = 0;
	root=myAlloc();
	cin >> n;
	for (int i = 0; i < n; i++) {
		char phoneNumber[11];
		cin >> phoneNumber;
		root->add(phoneNumber);
	}

}
void solve() {

	input();
	
	cout << (root->isOk() ? "YES\n" : "NO\n");


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	
	for (int t = 0; t < T; t++) {

		solve();
	}

	return 0;
}

