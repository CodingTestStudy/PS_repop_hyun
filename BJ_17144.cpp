//미세먼지 안녕! #17144 BJ
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//상하좌우
int yy[4] = {-1, 1, 0, 0};
int xx[4] = { 0, 0, -1, 1 };

int R, C, T;
int arr[51][51];

//반시계 방향 인덱스
pair<int, int> ccw[4] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
//시계 방향 인덱스
pair<int, int> cw[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;

	//공기청정기의 위쪽 아래쪽 좌표 표시
	int airY = -1, airX = -1, airY2 = -1, airX2 = -1;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
			{
				if (airY == -1)
					airY = i, airX = j;
				else
					airY2 = i, airX2 = j;
			}
		}

	for (int t = 0; t < T; t++)
	{
		queue<pair<int, int>> q;

		for (int i = 0; i < R; i++)//확산될 먼지 큐에 저장
			for (int j = 0; j < C; j++)
				if (arr[i][j] >= 1)
					q.push({ i, j });

		//배열복사
		int copyArr[51][51] = { 0, };
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				copyArr[i][j] = arr[i][j];

		//미세먼지 확산
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			int temp = copyArr[y][x] / 5;
			for (int i = 0; i < 4; i++)
			{
				int nextY = y + yy[i];
				int nextX = x + xx[i];

				if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C)
					if (copyArr[nextY][nextX] >= 0)
					{
						arr[nextY][nextX] += temp;
						arr[y][x] -= temp;
					}
			}
		}

		//미세먼지가 확산된 배열을 복사하고
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				copyArr[i][j] = arr[i][j];

		//공기청정기
		//위쪽
		int y = airY;
		int x = airX + 1;
		arr[y][x] = 0; //공기 바람 시작 지점 아무것도 없음
		for (int i = 0; i < 4; i++)
		{
			while (1)
			{
				int nextY = y + ccw[i].first;
				int nextX = x + ccw[i].second;

				if (nextY == airY && nextX == airX) //공기 청정기 도달시
					break;
				if (!(0 <= nextY && nextY < R && 0 <= nextX && nextX < C))
					break;

				arr[nextY][nextX] = copyArr[y][x];
				y = nextY;
				x = nextX;
			}
		}
		//아래쪽
		//시계 공기청정
		y = airY2;
		x = airX2 + 1;
		arr[y][x] = 0; //공기 바람 시작 지점 아무것도 없음
		for (int i = 0; i < 4; i++)
		{
			while (1)
			{
				int nextY = y + cw[i].first;
				int nextX = x + cw[i].second;

				if (nextY == airY2 && nextX == airX2)
					break;
				if (!(0 <= nextY && nextY < R && 0 <= nextX && nextX < C))
					break;

				arr[nextY][nextX] = copyArr[y][x];
				y = nextY;
				x = nextX;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (arr[i][j] >= 1)
				result += arr[i][j];

	cout << result << "\n";
	return 0;
}