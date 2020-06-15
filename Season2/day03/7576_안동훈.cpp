#include<bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define MAX 1005
int M, N, days;
int box[MAX][MAX];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool check, change;
queue<pair<int,int>> ripe;

void check_tomate(){
	check = true;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(box[i][j] == 0){
				check = false;
			}
		}
	}
}


void bfs(){
	change = true;
	days = -1;
	while(change){
		change = false;
		int today = ripe.size();
		for(int i=0; i<today; i++){
			auto cur = ripe.front();
			for(int j=0; j<4; j++){
				int nx = cur.X + dx[j];
				int ny = cur.Y + dy[j];
				if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if(box[nx][ny] == -1 || box[nx][ny] == 1) continue;
				box[nx][ny] = 1;
				ripe.push({nx, ny});
				change = true;
			}
			ripe.pop();
		}
		days++;
	}
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> M >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> box[i][j];
			if(box[i][j] == 1) {
				ripe.push(make_pair(i,j));
			}
		}
	}

	check_tomate();
	if(check) {
		cout << 0;
		return 0;
	}

	bfs();

	check_tomate();
	if(!check) {
		cout << -1;
		return 0;
	}
	cout << days << '\n';

    return 0;
}
