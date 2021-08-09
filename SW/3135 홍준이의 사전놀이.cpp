#define ALPHABETS_CNT 26
#define MAXN 100000

struct Trie;
Trie* Alloc();
int nodeCnt;
struct Trie {
	Trie* _children[ALPHABETS_CNT];
	int childCnt;
	bool fin;
	void add(const char* word) {
		childCnt++;
		if (*word != 0) {
			if (_children[*word - 'a'] == nullptr)_children[*word - 'a'] = Alloc();
			_children[*word - 'a']->add(word + 1);

		}
		else {
			fin = true;
		}
	}

	

	int get(const char* word) {
		
		if (*word != 0) {
			if (_children[*word - 'a'] != nullptr)return _children[*word - 'a']->get(word + 1); 
			return 0;
		}
		else {
			return childCnt;
		}
		
	}

	void clear() {
		for (int i = 0; i < ALPHABETS_CNT; i++) {
			_children[i] = nullptr;
		}
		fin = false;
		childCnt = 0;
	}

};

Trie Node[MAXN * 11];
Trie* root;
Trie* Alloc() {
	Trie* ret = &Node[nodeCnt++];
	ret->clear();
	return ret;
}


void init(void) {
	nodeCnt = 0;
	root = Alloc();
}

void insert(int buffer_size, char* buf) {
	
	root->add(buf);

}

int query(int buffer_size, char* buf) {
	int ans = root->get(buf);

	return ans;