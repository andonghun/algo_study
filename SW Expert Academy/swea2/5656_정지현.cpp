#include<iostream>
#include<queue>

using namespace std;

int map[15][15];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,w,h;
int answer;

struct Node{
    int x;
    int y;	
    int value; 
    Node(int a,int b, int c): x(a), y(b), value(c){};
};

void merge() {
	for (int i = 0; i < w; i++) {
		queue<int> q;
		int cnt = 0;

		for (int j = 0; j < h; j++) {
			if (map[j][i] != 0) {
				q.push(map[j][i]);
			} else {
				cnt++;
			}
		}

		for (int j = 0; j < h; j++) {
			if (j < cnt) map[j][i] = 0;
			else {
				map[j][i] = q.front();
				q.pop();
			}
			
		}

	}

}
void crush(int col) {
	queue<Node> q;

	for (int i = 0; i < h; i++) {
		if (map[i][col] != 0) {
			/*
			구슬이 명중한 위치와 폭발 범위를 저장
			-1 하는 이유 : 값이 1이면 자신을 제외하고 상하좌우 0칸씩 포함
			*/
			q.push(Node(i, col, map[i][col] - 1));
			map[i][col] = 0;
			break;
		}
	}

	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int val = q.front().value;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			// 폭발 범위 만큼 제
			for (int j = 0; j < val; j++) {
				nx += dx[i];
				ny += dy[i];

				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (map[nx][ny] != 0) {
					q.push(Node(nx, ny, map[nx][ny] - 1));
				}

				map[nx][ny] = 0;

			}
		}
	}

}
void dfs(int cnt) {
	if (cnt == n) {
		int total = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != 0) {
					total++;
				}
			}
		}

		answer = answer > total ? total : answer;
		return;
	}

	int tmp[15][15];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < w; i++) {
		crush(i); // 깨뜨리기
		merge(); // 다시 정렬
		dfs(cnt+1);
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				map[j][k] = tmp[j][k];
			}
		}

	}

}
int main(int argc, char** argv) {
	int test_case;
	int T;
	
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		answer = 987654321;

		dfs(0);

		printf("#%d %d\n", test_case, answer);
	
	}

	return 0;
}