#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visited[100][100];
int n;

int bfs(int x, int y) {	
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));

	while(!q.empty()) {
		for (int i = 0; i < 4; ++i) {
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!visited[nx][ny] && map[nx][ny] != 0) {
					q.push(make_pair(nx,ny));
					visited[nx][ny] = true;
				}
			}
		}

		q.pop();
	}
	
}
	
int main(int argc, char** argv){
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case) {
		cin >> n;

		int mv = 0;
		int answer = 1;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if (map[i][j] > mv) mv = map[i][j];
			}
		}

		for (int i = 1; i < mv; i++) {
			int cnt = 0;
			memset(visited, false, sizeof(visited));

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (i == map[j][k]) {
						map[j][k] = 0;
					}
				}
			}
			
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (map[j][k] != 0 && !visited[j][k]) {
						visited[j][k] = true;
						bfs(j,k);
						cnt++;
					}
				}
			}

			if (cnt > answer) answer = cnt;			
		}

		printf("#%d %d\n", test_case, answer);

	}

	return 0;
}