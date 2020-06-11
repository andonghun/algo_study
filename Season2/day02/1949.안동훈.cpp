// 1949. [모의 SW 역량테스트] 등산로 조성
// DFS, 완전탐색
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq&

#include<bits/stdc++.h>

using namespace std;

int answer;
int N, K, t;
int mt[8][8];
int temp[8][8];
bool visited[8][8];
vector<pair<int, int>> top;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void find(int x, int y, int dist) {
	if (dist > answer) answer = dist;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;

		if (mt[x][y] > mt[nx][ny]) {// 내리막 길
			find(nx, ny, dist + 1);
		}
	}

	visited[x][y] = false;
}

void work() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= K; k++) {

				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < N; jj++) {
						temp[ii][jj] = mt[ii][jj];
					}
				}

				// i, j 위치에 k만큼 공사
				mt[i][j] -= k;
				if (mt[i][j] < 0) mt[i][j] = 0;

				for (int st = 0; st < top.size(); st++) { // top 후보군 마다 길 찾기
					int cx = top[st].first;
					int cy = top[st].second;

					find(cx, cy, 1);
					memset(visited, 0, sizeof(visited));
				}

				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < N; jj++) {
						mt[ii][jj] = temp[ii][jj];
					}
				}

			}

		}
	}
}

void calculate() {
	// 공사 (완전 탐색)
	work();
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mt[i][j];
			t = max(t, mt[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mt[i][j] == t) top.push_back({ i, j });
		}
	}
}

void init() {
	answer = 0;
	t = 0;
	memset(mt, 0, sizeof(mt));
	memset(visited, 0, sizeof(visited));
	top.clear();
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();
		calculate();

		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}
