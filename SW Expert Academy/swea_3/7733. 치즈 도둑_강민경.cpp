// 40점

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cheese[101][101];
int total = 0; // N*N 배열에서 먹고 남은 치즈의 갯수
int idx; // seq 배열에서 현재 가리키는 idx번째 행

int max_day = 0;
int N;
int max_count = 1;
int visited[101][101];

// 상하좌우
int dx[4] = {0, 0, -1, 1};  
int dy[4] = {1, -1, 0, 0 }; 

void eat(int day);
void getCount(int x, int y);

// day일 때 visited에 치즈요정이 먹은 위치를 true로 바꿔주는 함수
void eat(int day) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cheese[i][j] == day) {
				cheese[i][j] = 0;
				total--;
			}
		}
	}
	
	// 덩어리 갯수 카운트
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] != 1 && cheese[i][j] > 0) { // 방문전
				getCount(i, j); // 덩어리의 갯수를 카운트함
				temp++;
			}
		}
	}

	if (temp > max_count) max_count = temp;

	return;
}

// day일때 덩어리의 갯수를 구하는 함수
void getCount(int x, int y) {

	visited[x][y] = 1; // 방문함
	int nx, ny;

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		// nx, ny 범위가 N*N 범위 안에 있어야함 
		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if(visited[nx][ny] == 0 && cheese[nx][ny] > 0)
				getCount(nx ,ny);
		}
	}
	return;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_case;
	int data;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		cin >> N;
		total = N * N;

		// 입력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cheese[i][j];
				visited[i][j] = 0;

				if (max_day < cheese[i][j]) max_day = cheese[i][j];
			}
		}
		
		for (int d = 0; d <= max_day; d++) {

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					visited[i][j] = 0; // 다시 초기화
				}
			}

			eat(d);
		}

		cout << "#" << t << " " << max_count << "\n";
	}

	return 0;
}
