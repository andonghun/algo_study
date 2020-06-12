//DFS문제+BFS문제 고군분투끝에 성공
// 실패했었던 이유
//1. 예외범위 설정미숙
//2. 컨테이너.size()의 (int)형 형변환 미숙
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;
int T, N, W, H;
int minv=400;
vector<deque<int>> brick_map;
queue <int> ansqu;
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void In() {
	cin >> N >> W >> H;
	for (int tp = 1; tp <= W; tp++) { 
		deque<int> dq;
		brick_map.push_back(dq);
	}
	int a;
	for (int i = 0;i<H; i++)
		for (int j = 0; j < W; j++) {
			cin >> a;
			if (a == 0)
				continue;
			brick_map[j].push_front(a);
		}
}
bool isinside(int i,int j)
{
	//범위 안에 있는지 검사
	if (i <= H - 1 && i >= 0 && j <= W - 1 && j >= 0) {
		
		if (i <= (int)brick_map[j].size() - 1)
			return true;
		else
			return false;
	}
	else
		return false;
}
void send_bfs(int j, int map[][12],int size) {//2차원배열을받기 위해 배열포인터사용.


	queue<pair<int, int>> qu;
	qu.push(  pair<int,int>(brick_map[j].size() - 1, j));
	
	if (brick_map[j].size() == 0)//예외처리
		return;
	map[brick_map[j].size() - 1][j] = brick_map[j][brick_map[j].size() - 1];//방문한 곳은  brick_map에있는 값을 집어넣음
	
	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();

		int curv = brick_map[curj][curi];
		if (curv == 1)
			continue;
		else
		{
			int inc= curv - 1;
			for (int tp1 = 0; tp1 < 4; tp1++) {
				int nexti= curi;
				int nextj= curj;
				for (int tp2 = 1; tp2 <= inc; tp2++)
				{
					nexti += dist[tp1][0];
					nextj += dist[tp1][1];

					//범위 밖인가?   , 이미 방문했던 곳인가?
					if ( !isinside(nexti, nextj)  ||  map[nexti][nextj]!=0 )
						continue;
					else{
						map[nexti][nextj] = brick_map[nextj][nexti];
						qu.push(pair<int,int>(nexti,nextj));
					}
				}
			}
		}
		
	}
		

	for(int i2=H-1;i2>=0; i2--)
		for (int j2 = 0; j2 < W; j2++) {
			if (map[i2][j2] != 0) {
				deque<int>::iterator iter= brick_map[j2].begin();
				iter += i2;
				brick_map[j2].erase(iter);
			}

		}
	
}
void back(int j, int map[][12]) { //의혹
	for(int i2=0; i2<H ; i2++)
		for (int j2 = 0; j2 < W; j2++) {
			if (map[i2][j2] != 0) {
				if (brick_map[j2].size() - 1 >= i2) {
					deque<int>::iterator iter = brick_map[j2].begin();
					iter += i2;
					brick_map[j2].insert(iter, map[i2][j2]);
				}
				else
					brick_map[j2].push_back(map[i2][j2]);

			}
				
		}

}
void dfs(int size) {
	//size==N ; 최적값갱신
	if (size == N) {
		int sum = 0;
		for (int tp = 0; tp < W; tp++)
			sum += brick_map[tp].size();
		if (sum < minv)
			minv = sum;
		return;
	}
		
	int map[15][12] = { 0, };//복구용도 ,이미 방문하였는지 확인 용도의 지도
	// 전부 0로 초기화 .   0 갈수있음을 의미 .    0이외의숫자는 이미방문함을 의미

	//W위치에 모든걸반복
	for (int j = 0; j < W; j++) {

		send_bfs(j,map,size);
		
		dfs(size + 1);
		back(j,map);//제거되기 전으로 만듬

		memset(map, 0, sizeof(map));//back이용후 map초기화
	}

}
int main() {
	cin >> T;
	for (int tp = 1; tp <= T; tp++) {
		In();
		dfs(0);
		ansqu.push(minv);
		
		//초기화
		minv = 400;
		brick_map.clear();
	}

	//정답출력
	int b=1;
	while (!ansqu.empty()) {
		cout << "#" << b << ' ' << ansqu.front()<<'\n';
		ansqu.pop();
		b++;
	}

}