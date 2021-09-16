#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <utility>
using namespace std;
typedef pair<int, int> P;
int N;
struct Node;
Node* Alloc(string , Node*);
P DFS(Node*);
Node* root;

struct Node {

	Node* parent;
	string name;
	set<string> Pchild;
	map<string, Node*> subAlbum; //하위 앨범들

	int albumCnt=0;
	int pictureCnt=0;
	

	void init(string n, Node* pa) {
		name = n;
		parent = pa;
		albumCnt = 0;
		pictureCnt = 0;
	}


	void del(string p) {
		if (p == "-1") {
			if (!Pchild.empty()) {
				auto f = Pchild.begin();
				Pchild.erase(f);
				cout << '1' <<'\n';
				pictureCnt--;
			}
			else cout << '0' << '\n';
		}
		else if (p == "0") {
			if (!Pchild.empty()) {

				pictureCnt = 0;
				cout << to_string(Pchild.size()) << '\n';
				Pchild.clear();


			}
			else cout << '0' << '\n';
		}
		else if (p == "1") {
			if (!Pchild.empty()) {
				auto f = prev(Pchild.end());
				Pchild.erase(f);
				cout << '1' << '\n';
				pictureCnt--;
			}
			else cout << '0' << '\n';
		}
		else {
			auto f = find(Pchild.begin(), Pchild.end(), p);
			if (f != Pchild.end()) {

				Pchild.erase(f);
				pictureCnt--;
				cout << '1' << '\n';
			}
			else {
				cout << '0' << '\n';
			}

		}

	}
	void rmalb(string a) {
	
		if (a == "-1") {
			if (!subAlbum.empty()) {
				map<string,Node*>::iterator f = subAlbum.begin();
				string key = f->first;
				Node* here = subAlbum[key];
				P ret = DFS(here);
				cout << ret.first + 1 << ' ' << ret.second << '\n';
				subAlbum.erase(key);
				albumCnt--;
			}
			else cout << '0' << ' ' << '0' << '\n';

				
			
		
			
		}
		else if (a == "0") {
		
				P ret = DFS(this); //현재 사진은 삭제 안함
				cout << ret.first<< ' ' << ret.second-pictureCnt << '\n';
				albumCnt= 0;
				subAlbum.clear();
			
		
		
		}
		else if (a == "1") {
			if (!subAlbum.empty()) {
				map<string, Node*>::iterator f = prev(subAlbum.end());
				string key = f->first;
				Node* here = subAlbum[key];
				P ret = DFS(here);
				cout << ret.first + 1 << ' ' << ret.second << '\n';
				subAlbum.erase(key);
				albumCnt--;
			}
			else cout << '0' << ' ' << '0' << '\n';
		}
		else {
			
			auto f = subAlbum.find(a);
			if (f != subAlbum.end()) { //있을때만
				string key =a;
				Node* here = subAlbum[key];
				P ret = DFS(here);
				cout << ret.first + 1 << ' ' << ret.second << '\n';
				subAlbum.erase(key);
				albumCnt--;
			}
			else {
				cout << '0' << ' ' << '0' << '\n';

			}

		}
	}

	Node* ca(string s) {
		if (s == "..") {

			if (name != "album")return parent;
			else return this;
			
			
		}
		else if (s == "/") {

			return root;
		}
		else {
			auto f = subAlbum.find(s);
			if (f!= subAlbum.end()) {

				return subAlbum[s];
			}
			else {
				return this;
			}
		}


	}

	void mkalb(string in) {
		if (subAlbum.find(in) != subAlbum.end()) {
			cout << "duplicated album name\n";
		}
		else {

			Node* n_node = Alloc(in,this);
			subAlbum[in] = n_node;
			albumCnt += 1;

		}
	}


	void insert(string in) {
		//중복체크
		if (find(Pchild.begin(), Pchild.end(), in) != Pchild.end()) {
			cout << "duplicated photo name\n";
		}
		else {
			Pchild.insert(in);
			pictureCnt+=1;
		}
		
	}

};



Node buf[100000+2];
int nodeCnt = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	root = Alloc("album",nullptr);
	Node* cur = root;
	
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "mkalb") {
			string S;
			cin >> S;
			cur->mkalb(S);

		}

		else if (cmd == "rmalb") {
			string S;
			cin >> S;
			cur->rmalb(S);
			
		}
		else if (cmd == "insert") {
			string S;
			cin >> S;
			cur->insert(S);
			
		}
		else if (cmd == "delete") {
			string S;
			cin >> S;
			cur->del(S);
		}
		else if (cmd == "ca") {
			string S;
			cin >> S;
			cur = cur->ca(S);
			cout << cur->name << '\n';
		}

	}
	
	return 0;

}

Node* Alloc(string name, Node* par) {
	Node* ret = &buf[nodeCnt++];
	ret->init(name, par);
	return ret;
}

P DFS(Node* cur) {
	P ret = { 0,0 };
	ret.first += cur->albumCnt;
	ret.second += cur->pictureCnt;
	for (auto n : cur->subAlbum) {
		P t = DFS(cur->subAlbum[n.first]);
		ret.first += (t.first);
		ret.second += (t.second);

	}

	return ret;

}



