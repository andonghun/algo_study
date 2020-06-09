// URL: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf&
// 1767. [SW Test 샘플문제] 프로세서 연결하기
// 완전탐색, DFS

#include<bits/stdc++.h>

using namespace std;

int N;
int MP[12][12];
bool visited[12][12];
int numberOfCore, maxCore, minLine;
vector<pair<int, int>> core;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int idx, int cores, int line) {
	if (idx == numberOfCore) {
		if (cores > maxCore) {
			maxCore = cores;
			minLine = line;
		}
		else if (cores == maxCore) {
			if (line < minLine) {
				minLine = line;
			}
		}
		return;
	}

	bool temp[12][12];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = visited[i][j];
		}
	}

	int cx = core[idx].first;
	int cy = core[idx].second;

	for (int i = 0; i < 4; i++) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];

		bool flag = true;
		int tempLine = 0;

		while (1) {
			if (0 > nx || nx >= N || 0 > ny || ny >= N) break;
			if (MP[nx][ny] == 1 || visited[nx][ny] == true) {
				flag = false;
				break;
			}

			visited[nx][ny] = true;
			nx += dx[i];
			ny += dy[i];
			tempLine++;
		}
		if (flag) {
			dfs(idx + 1, cores + 1, line + tempLine);
		}

		if (tempLine > 0) {
			for (int ii = 0; ii < N; ii++) {
				for (int jj = 0; jj < N; jj++) {
					visited[ii][jj] = temp[ii][jj];
				}
			}
		}
	}
	dfs(idx + 1, cores, line);
}

void calculate() {
	//dfs의 인수에 대한 고민.. core idx, current connected cores num, sum of lines
	dfs(0, 0, 0);
	return;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MP[i][j];
			//코어가 가장자리에 있는 경우
			if (i == 0 || j == 0 || i == N - 1 || j == N - 1) {
				continue;
			}
			else if (MP[i][j] == 1) {
				core.push_back({ i, j });
				numberOfCore++;
			}
		}
	}
}

void init() {
	memset(MP, 0, sizeof(MP));
	memset(visited, 0, sizeof(visited));
	core.clear();
	numberOfCore = 0;
	maxCore = 0;
	minLine = 987654321;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		init();
		input();
		calculate();

		cout << "#" << test_case << " " << minLine << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
