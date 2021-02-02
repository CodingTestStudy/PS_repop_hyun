//백준 2477 참외밭

#include <iostream>
using namespace std;

int arr[6];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int K;
	int D, L;
	int ret;
	int outsideRow =0;
	int outsideCol=0;
	int insideRow=0;
	int insideCol=0;

	cin >> K;

	for (int i = 0; i < 6; i++) {
		cin >> D >> L;

		arr[i] = L;
	}

	for (int i = 0; i < 6; i++) {
		//짝수번째는 항상 Row로 취급
		if (i % 2 == 0) {
			if (outsideRow < arr[i]) {
				outsideRow = arr[i];
			}
		
		}
		else {
			if (outsideCol < arr[i]) {
				outsideCol = arr[i];
			}
		}
	}


	
	for (int i = 0; i < 6; i++) {
		
		if (i % 2 == 0) { //짝수 번째 양옆 변 합이 바깥 높이와 같을때, 안쪽 사각형임

			if (arr[(i + 5) % 6] + arr[(i + 1) % 6] == outsideCol) {
				insideRow = arr[i];
			}
		}
		else {
			if (arr[(i + 5) % 6] + arr[(i + 1) % 6] == outsideRow) {
				insideCol = arr[i]; 
			}

		}
		
	}

	ret = outsideCol * outsideRow - insideCol * insideRow;

	cout << ret * K << '\n';
	return 0;

}