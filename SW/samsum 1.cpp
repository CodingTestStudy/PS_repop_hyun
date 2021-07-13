#define N 4
#include<stdio.h>

typedef struct {
	int hit;
	int miss;
} Result;

// API
extern Result query(int guess[]);

int num[10];
int arr[4];
bool visited[4] = { false };
bool isEnd = false;
void init() {

	isEnd = false;
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		arr[i] = 0;
	}

}

void permu(int cnt, int guess[]) {

	if (cnt == 4) {

		Result ret = query(arr);
		if (ret.hit == 4) {
			isEnd = true;
			for (int i = 0; i <= 3; i++) {
				guess[i] = arr[i];
			}
	
		}

	}
	else {
		for (int i = 0; i <= 3; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[cnt] = guess[i];
				permu(cnt + 1, guess);
				if (isEnd == true)break;
				visited[i] = false;

			}
		}

	}
}

void combi(int cnt, int idx, int guess[]) {

	if (idx == 4) {

		Result ret = query(guess);
		if (ret.hit + ret.miss == 4) {
			permu(0, guess);
			if (isEnd == true)return;

		}


	}
	else {

		for (int i = cnt; i < 10; i++) {
			guess[idx] = num[i];
			combi(i + 1, idx + 1, guess);
			if (isEnd == true)break;
		}

	}



}

void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	//
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.
	init();
	for (int i = 0; i <= 9; i++) {
		num[i] = i;
	}
	combi(0, 0, guess);
	
}