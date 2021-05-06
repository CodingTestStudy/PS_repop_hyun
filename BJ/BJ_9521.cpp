#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string A, B;
int arr[1000 + 2][1000 + 2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A;
	cin >> B;

	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			if(A[i] == B[j]){
				arr[i + 1][j+1] = arr[i][j] + 1;
			}

			else {
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
			}
			
		}
	}
	

	cout << arr[A.length()][B.length()] << '\n';
	return 0;

}
