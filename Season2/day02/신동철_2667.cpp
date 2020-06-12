//BFS�� ����
//������ ���ǿ� ���� �ȹٷ� ��ɾ� ���������༭ ���� �����Ÿ�.
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
vector<int> vec;//�������Ѻ���
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
	map[i][j] = false;//Ž���Ϸ�ǥ��
	cnt++;

	while (!qu.empty()) {
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();
		//4����Ž��
		for (int tp = 0; tp < 4; tp++) {
			int nexti = dist[tp][0] + curi;
			int nextj = dist[tp][1] + curj;
			
			//���� �ȿ��ְ�,bottle�� �ش簪�� 1�̰�,Ž���� ���� ������,
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
			if (map[i][j] == true) {//true �� ���� Ž�� ���� ���̸� ,���� �����
				vec.push_back(bfs(i,j));
			}
		}
	sort(vec.begin(), vec.end(), less<int>());
	//�������
	cout << vec.size() << '\n';
	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter<<'\n';
}