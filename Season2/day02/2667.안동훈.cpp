// 단지번호붙이기
// DFS
// https://www.acmicpc.net/problem/2667

#include <bits/stdc++.h>
using namespace std;

int N;
int m[25][25];
bool visited[25][25];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int cnt; // 단지 개수
vector<int> v;

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (!visited[nx][ny] && m[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		for (int j = 0; j < N; j++) {
			if (x[j] == '1') m[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == 1 && !visited[i][j]) { // 집이면서, 방문하지 않았으면
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
