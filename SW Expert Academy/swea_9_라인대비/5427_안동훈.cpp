#include<bits/stdc++.h>

using namespace std;

char building[1000][1000];
int visited[1000][1000];
bool fires[1000][1000];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int w, h;
bool possible;
int cnt;
queue<pair<int, int>> q, fire;

void init() {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			visited[i][j] = -1;
			fires[i][j] = false;
		}
	}
	while (!q.empty()) q.pop();
	while (!fire.empty()) fire.pop();
	possible = false;
}

void bfs() {
	pair<int, int> st;
	pair<int, int> fire_st;

	while (!q.empty()) {

		int size = q.size();
		int fire_num = fire.size();

		for (int ii = 0; ii < fire_num; ii++) {
			fire_st = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int fx = fire_st.first + dx[i];
				int fy = fire_st.second + dy[i];
				if (fx < 0 || fx >= h || fy < 0 || fy >= w) continue;
				if (building[fx][fy] == '#' || fires[fx][fy] == true) continue;
				if (fires[fx][fy] == false) {
					fires[fx][fy] = true;
					fire.push({ fx, fy });
				}
			}
		}
		for (int ii = 0; ii < size; ii++) {
			st = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = st.first + dx[i];
				int ny = st.second + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					possible = true;
					cnt = visited[st.first][st.second];
					return;
				}
				if (visited[nx][ny] > 0 || building[nx][ny] == '#' || fires[nx][ny] == true) continue;
				if (building[nx][ny] == '.') {
					visited[nx][ny] = visited[st.first][st.second] + 1;
					q.push({ nx,ny });
				}
			}
		}

	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> w >> h;
		string s;

		init();

		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				building[i][j] = s[j];
				if (building[i][j] == '@') {
					q.push({ i,j });
					visited[i][j] = 1;
				}
				else if (building[i][j] == '*') {
					fire.push({ i,j });
					fires[i][j] = true;
				}
			}
		}

		bfs();

		if (possible) {
			cout << cnt << "\n";
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
		}
	}
	return 0;
}
