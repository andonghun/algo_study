// 1249. [S/W 문제해결 응용] 4일차 - 보급로
// 
#include<iostream>
#include<string.h>
#include <stdio.h>
using namespace std;

int arr[101][101];
int countmap[101][101];

int t, n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void map(int x, int y, int sum) {
	
	countmap[x][y] = sum;

	//1. 기저조건, 범위를 벗어나면 종료
	if (x < 0 || y < 0 || x == n || y == n) return;

	// 2. countmap이 기본값 0이면 저장
	//		만약 countmap이 값이 들어온 상태인데 
	//		sum + arr[x][y] < count[x][y] 이면 count값을 변경해줌

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ( (nx >= 0 && nx < n) ||( ny >= 0 && ny < n) ) {
			int cnt = arr[nx][ny] + sum;

			if (cnt < countmap[nx][ny] || countmap[nx][ny] == 0) {
				map(nx, ny, cnt);
			}
		}
		else continue;
	}
	return;
}

int main(int argc, char** argv)
{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);

	int test_case;

	scanf("%d", &t);
	
	for (test_case = 1; test_case <= t; ++test_case)
	{
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		memset(countmap, 0, sizeof(countmap));

		// 입력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]);

			}
		}
		map(0,0,0);

		printf("%d %d\n", t, countmap[n - 1][n - 1]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


			//	char ch = getchar();
			//	int a = ch - '0';
			//	scanf_s("%d", &arr[i][j]);
			//	cin >> arr[i][j];
