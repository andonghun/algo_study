//제대로 안됨 ㅋ

#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int grid[351][351];

class info {
public:
	int x;
	int y;
	int life; // 생명력
	int status; // 상태: 0 비활성화 1 활성화 2 죽음
	int count;
};

vector<info> stem_cells, temp;

bool cmp(info a, info b) {
	return a.life > b.life;
}

void counting() { // count 세는 용도
	for (int i = 0; i < stem_cells.size(); i++) {
		//예외 처리: status가 2일 때, skip
		if (stem_cells[i].status == 2) continue;
		if (stem_cells[i].status == 0) {
			stem_cells[i].count--;
			if (stem_cells[i].count == 0) {
				stem_cells[i].status = 1;
				stem_cells[i].count = stem_cells[i].life;
			}
		}
		else if (stem_cells[i].status == 1) {
			stem_cells[i].count--;
			if (stem_cells[i].count == stem_cells[i].life - 1) {
				temp.push_back(stem_cells[i]);
			}
			if (stem_cells[i].count == 0) {
				stem_cells[i].status = 2;
			}
		}
	}
}

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void breeding() {
	int size = temp.size();
	for(int i=0; i<size; i++){
		 // 활성 상태이면서 활성한 지 1시간 째일 경우 번식
		info cur = temp[i];
		int cx = cur.x;
		int cy = cur.y;
		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];
			if (grid[nx][ny] == 0) {
				grid[nx][ny] == cur.life;
				stem_cells.push_back({ nx,ny,cur.life, 0, cur.life });
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> M >> K;
		//초기화
		memset(grid, 0, sizeof(grid));
		stem_cells.clear();
		temp.clear();

		for (int i = 150; i < 150 + N; i++) {
			for (int j = 150; j < 150 + M; j++) {
				cin >> grid[i][j];
				if (grid[i][j] != 0) {
					stem_cells.push_back({ i,j,grid[i][j],0,grid[i][j] });
				}
			}
		}

		for (int ii = 0; ii < K; ii++) {
			sort(stem_cells.begin(), stem_cells.end(), cmp); // life 기준으로 정렬

			counting(); // 1시간 증가

			sort(temp.begin(), temp.end(), cmp); // life 기준으로 정렬

			breeding(); // 번식
		}
		int cnt = 0;
		for (int i = 0; i < stem_cells.size(); i++) {
			if (stem_cells[i].status == 2) continue;
			cnt++;
		}
		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
