#include<iostream>

using namespace std;

int map[51][51];
int dx[4] = {-1,0,1,0}; // 북,동,남,서
int dy[4] = {0,1,0,-1};

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

	int r, c, dir, x, y;
	cin >> r >> c;
	cin >> x >> y >> dir;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
		}
	}

	map[x][y] = -1;
	int answer = 1;
	int nx, ny;

	while(1) {
		int cnt = 0;
		int flag = false;
		int d = dir; // 원래 방향 복사

		for (int i = 0; i < 4; ++i) {
			dir = (dir+3) % 4; // 바라보는 방향 기준 왼쪽 방향

			nx = dx[dir] + x;
			ny = dy[dir] + y;

			if (map[nx][ny] == 0) {
				flag = true;
				break;
			} else if (map[nx][ny] != 0 || nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cnt++;
			}
		}

		if (flag) {
			map[nx][ny] = -1;
			answer++;
		} 

		if (cnt == 4) {
			dir = d;

			nx = x - dx[dir];
			ny = y - dy[dir]; 

			// 뒤쪽 방향이 벽일 때
			if (map[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= r || ny >= c){ 
				break;
			}
				
		} 

		x = nx;
		y = ny;
	}

	cout << answer;

	return 0;
}