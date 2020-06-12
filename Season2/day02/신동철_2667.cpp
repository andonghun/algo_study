//BFS로 성공
//문제의 조건에 대해 똑바로 명령어 구성안해줘서 조금 버벅거림.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

int N;
int bottle[25][25];
bool map[25][25];
int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<int> vec;//정렬위한벡터
void In()
{
	cin >> N;
	int a;
	for(int i=0; i<N ; i++)
		for (int j = 0; j < N; j++) {
			scanf("%1d", &a);
			bottle[i][j] = a;
			if (a == 1)
				map[i][j] = true;
			else
				map[i][j] = false;
		}


}
bool isinside(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	else
		return false;
}
int bfs(int i,int j) {
	int cnt = 0;
	queue<pair<int, int>> qu;
	qu.push(pair<int, int>(i, j));
	map[i][j] = false;//탐색완료표시
	cnt++;

	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();
		//4방향탐색
		for (int tp = 0; tp < 4; tp++) {
			int nexti = dist[tp][0] + curi;
			int nextj = dist[tp][1] + curj;
			
			//범위 안에있고,bottle의 해당값이 1이고,탐색한 적이 없으면,
			if (isinside(nexti, nextj) && bottle[nexti][nextj] == 1 && map[nexti][nextj] == true) {
				map[nexti][nextj] = false;
				cnt++;
				qu.push(pair<int, int>(nexti, nextj));
			}
		}
		
	}
	return cnt;
}

int main()
{
	In();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j] == true) {//true 인 경우는 탐색 안한 곳이며 ,집인 경우임
				vec.push_back(bfs(i,j));
			}
		}
	sort(vec.begin(), vec.end(), less<int>());
	//정답출력
	cout << vec.size() << '\n';
	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter<<'\n';
}