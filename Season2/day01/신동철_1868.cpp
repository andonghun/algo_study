//성공
//BFS로 해결
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int T, N;
char ary[300][300];
bool map[300][300];
int dist[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
int cnt = 0;
queue<pair<int, int>> corqu;// 주위8곳에 지뢰가 없는경우 좌표
queue<int> qu;//정답용큐
void In() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> ary[i][j];
			if (ary[i][j] == '*')
				map[i][j] = false;//지뢰자리는 false
			else
				map[i][j] = true;//갈수있는 자리는 true
		}
}
bool isinside(int i,int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
void insert_qu() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			//선택한 값이 지뢰면 continue
			if (ary[i][j] == '*')
				continue;
			int tp = 0;
			//8곳이 범위안에있는가? 
			for (; tp < 8; tp++) {
				//범위 안에 있으면 검사.
				if (isinside(dist[tp][0] + i, dist[tp][1] + j)) {
					if (ary[dist[tp][0] + i][dist[tp][1] + j] == '*') 
						break;
				}
					//범위밖이면 
				else
					continue;
			}
			if (tp == 8)
				corqu.push(pair<int,int>(i,j));
		}
			
}
void bfs() {
	while (!corqu.empty()) {
		
		queue<pair<int, int>> conqu;
		int curx = corqu.front().first;
		int cury = corqu.front().second;
		corqu.pop();
		if (map[curx][cury] == false)
			continue;
		cnt++;
		conqu.push(pair<int, int>(curx, cury));

		while (!conqu.empty()) {
			curx = conqu.front().first;
			cury = conqu.front().second;
			conqu.pop();
			//갈수있는 장소이고 , 지뢰가 아닐경우
			if (map[curx][cury] == true && ary[curx][cury] != '*')
			{
				map[curx][cury] = false;//이미 탐험한걸로 표시

				queue<pair<int, int>>bufqu;
				int tp = 0;
				for (; tp < 8; tp++) {
					//범위 안에 있고
					if (isinside(dist[tp][0] + curx, dist[tp][1] + cury)) {
						//주위에 지뢰가 하나라도 있으면 break;
						if (ary[dist[tp][0] + curx][dist[tp][1] + cury] == '*') {
							break;
						}
						bufqu.push(pair<int, int>(dist[tp][0] + curx, dist[tp][1] + cury));
					}
					//범위밖이면 
					else
						continue;
				}
				//주위에 지뢰가 하나도 없는경우
				if (tp == 8) {
					while (!bufqu.empty()) {
						conqu.push(bufqu.front());
						bufqu.pop();
					}
				}
			}

		}
	}
}

int main()
{
	cin >> T;
	for (int tp = 0; tp < T; tp++) {
		In();
		
		insert_qu();//주위8곳에 *가 없는 좌표를 corqu에 넣음
		bfs();//corqu를 pop시키면서 연쇄작업시키는데, 연쇄작업한번당 cnt가 하나증가.

		//한점 주위에 지뢰가 하나라도 있는경우를 카운트시킴
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (  map[i][j] == false )
					continue;
				if (ary[i][j] == '.')
					cnt++;
			}
		qu.push(cnt);
		cnt = 0;//초기화
	}

	//정답출력
	int a = 1;
	while (!qu.empty()) {
		cout << '#' << a << ' ' << qu.front() << '\n';
		qu.pop();
		a++;
	}
	
}