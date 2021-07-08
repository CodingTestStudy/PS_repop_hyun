
//트리순회
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<char> tree[27];
int N;

void pre(char r) {

	cout << r;
	if (tree[r - 65][0] != '.')pre(tree[r - 65][0]);
	if(tree[r - 65][1] != '.')pre(tree[r - 65][1]);


}

void in(char r) {

	if (tree[r - 65][0] != '.')in(tree[r - 65][0]);
	cout << r ;
	if (tree[r - 65][1] != '.')in(tree[r - 65][1]);

}

void post(char r) {

	if (tree[r - 65][0] != '.')post(tree[r - 65][0]);
	if (tree[r - 65][1] != '.')post(tree[r - 65][1]);
	cout << r ;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	char input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		char r = input;
		for (int j = 0; j < 2; j++) {
			cin >> input;
			tree[r - 65].push_back(input);

		
		}
		
	}

	
	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	return 0;

}
