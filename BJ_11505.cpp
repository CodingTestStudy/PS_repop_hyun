//백준 11505 구간 곱 구하기

#include <iostream>
#include <vector>
using namespace std;

long long N, M, K;
long long arr[1000001];
class seg {
public:
	vector<long long> v;

	seg(long long n) {
		long long size = n * 4;
		v.resize(size);
		init(1,0,int(n-1));
	}

	long long init(int nodeNum, int left, int right) {
		
		if (left == right)return v[nodeNum] = arr[left] % 1000000007;
		
		int mid = (left + right) / 2;
		return v[nodeNum] = (init(nodeNum * 2, left, mid) * init( nodeNum * 2 + 1, mid + 1, right)) % 1000000007;

		
	}
	
	long long multi(int left, int right, int nodeNum, int b, int c) {

		if(right < b || c < left)return 1;

		if(b <= left && right <= c)return v[nodeNum] % 1000000007;

		int mid = (left + right) / 2;
		return (multi(left, mid , nodeNum*2,b,c) * multi(mid+1, right, nodeNum*2 + 1,b,c)) % 1000000007;
	}

	long long update(int left, int right,int nodeNum ,int b, int c) {
		
		if (left==right)return v[nodeNum] = c % 1000000007;
		int mid = (left + right) / 2;
		if (b <= mid) {
			return v[nodeNum] = (update(left,mid,nodeNum*2,b,c) * v[nodeNum * 2 + 1]) % 1000000007;
		}
		else if (mid < b) {
			return v[nodeNum] = (update(mid+1, right, nodeNum * 2 + 1, b, c) * v[nodeNum * 2]) % 1000000007;
		}
	}


};

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {

		cin >> arr[i];
	}

	seg s(N);
	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		// b번째를 c으로 변경
		if (a == 1) {
			s.update(0,N-1,1,b-1, c);
		}
		// b 부터 c까지 곱 출력
		else if (a == 2) {
			cout << s.multi(0, N - 1, 1, b - 1, c - 1) % 1000000007 << '\n';
		}
	}
	
	return 0;

}