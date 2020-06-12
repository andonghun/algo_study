// 5656. [모의 SW 역량테스트] 벽돌 깨기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo

// 참고 https://regularmember.tistory.com/m/119
#include <iostream>
#include <queue>
using namespace std;


int n, w, h, ans;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int count(int newmap[15][12]) {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			//0이 아닌 칸(벽돌이 남아있는 칸)을 계산
			if (newmap[i][j] != 0) cnt++;
		}
	}

	return cnt;
}


//벽돌 밑으로 떨어진다.
void move(int newmap[15][12]) {
	//모든 열을 검사
	for (int j = 0; j < w; j++) {
		bool flag = false;
		for (int i = h - 1; i >= 0; i--) {
			if (newmap[i][j] != 0) continue;

			//빈칸을 찾았으면 다시 위쪽에 떠 있는 벽돌을 찾아준다.
			for (int k = i - 1; k >= 0; k--) {
				if (newmap[k][j] == 0) continue;

				newmap[i][j] = newmap[k][j];
				newmap[k][j] = 0;
				flag = true;
				break;
			}

			//위에 떠있는 벽돌이 없으므로 다음열을 검사해주면 된다.
			if (!flag) break;

		}
	}
}

//벽돌을 부순다.
void go(int x, int y, int newmap[15][12]) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int num;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		num = newmap[x][y];

		newmap[x][y] = 0;

		if (num == 1) continue;

		//네방향으로 num-1번만큼 벽돌 제거, 1보다 크면 큐에 추가
		for (int k = 0; k < 4; k++) {
			int nx = x;
			int ny = y;
			for (int l = 0; l < num - 1; l++) {
				nx += dx[k];
				ny += dy[k];

				if (nx < 0 || ny < 0 || nx >= h || ny >= w) break;

				if (newmap[nx][ny] > 1) {
					q.push(make_pair(nx, ny));
				}
				else {
					newmap[nx][ny] = 0;
				}

			}

		}
	}
}


void mapcpy(int map[15][12], int newmap[15][12]) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			newmap[i][j] = map[i][j];
		}
	}
}


void solve(int index, int map[15][12]) {
	if (index == n) {
		int tmp = count(map);
		if (ans > tmp) ans = tmp;

		return;
	}


	int x, y;
	//모든 열에서 구슬을 쏘는 경우를 구한다.
	for (int col = 0; col < w; col++) {
		x = 0;
		y = col;

		//맨 위의 벽돌을 찾는다.
		while (true) {
			//이번 열이 다 깨져있다.
			if (x >= h) {
				break;
			}

			//맨 위 벽돌을 찾았다.
			if (map[x][y] != 0) {
				break;
			}

			//밑의 칸으로 이동
			x++;
		}

		//이번 열에 벽돌이 없으면 다음 선택한 열로 넘어간다.
		if (x == h) continue;

		int newmap[15][12];
		mapcpy(map, newmap);

		//구슬 쏜다.
		go(x, y, newmap);

		//벽돌 내려온다.
		move(newmap);

		solve(index + 1, newmap);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> w >> h;
		ans = 200;

		int map[15][12];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		solve(0, map);

		if (ans == 200) {
			//ans가 초기값인 경우에는 0을 출력(처음부터 다 깨져있는 경우)
			cout << '#' << tc << ' ' << 0 << '\n';
		}
		else {
			cout << '#' << tc << ' ' << ans << '\n';
		}

	}


	return 0;
}
