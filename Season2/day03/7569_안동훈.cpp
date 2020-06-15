#include<bits/stdc++.h>

using namespace std;

#define MAX 102
int M, N, H, days;
int box[MAX][MAX][MAX];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
bool check, change;
queue<tuple<int,int,int>> ripe;

void check_tomate(){
	check = true;
	for(int i=0; i<H; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				if(box[j][k][i] == 0) {
					check = false;
				}
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
			for(int j=0; j<6; j++){
				int nx = get<1>(cur) + dx[j];
				int ny = get<0>(cur) + dy[j];
				int nz = get<2>(cur) + dz[j];
				if(nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
				if(box[ny][nx][nz] == -1 || box[ny][nx][nz] == 1) continue;
				box[ny][nx][nz] = 1;
				ripe.push(make_tuple(ny, nx, nz));
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

	cin >> M >> N >> H;

	for(int i=0; i<H; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				cin >> box[j][k][i];
				if(box[j][k][i] == 1) {
					ripe.push(make_tuple(j, k, i));
				}
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
