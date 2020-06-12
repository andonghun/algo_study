// https://www.acmicpc.net/problem/2667
// 2667 단지번호붙이기
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int MAX = 30;

char myGraph[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int complex[MAX] = { 0, };// 마을의 갯수
int cidx = 0; // 단지수

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;


void go(int x, int y) { // x좌표, y좌표
	// myGraph가 1이면 진행함!!

	visited[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if ((next_x >= 0 && next_x < n) && (next_y >= 0 && next_y < n)) {
			if (myGraph[next_x][next_y] == '1' && visited[next_x][next_y] == 0)
				go(next_x, next_y);
		}

	}
	return;
}

int main() {

	scanf("%d", &n);

	// 배열입력

	for (int i = 0; i < n; i++) {
		scanf("%s", myGraph[i]);
	}

	
	// 검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int count;
			if (myGraph[i][j] == '1' && visited[i][j] == 0) {
				go(i, j);
				complex[cidx++] = cnt;
				cnt = 0;
			}

		}
	}

	printf("%d\n", cidx);

	int max = -987987987;

	std::sort(complex, complex + cidx);
	for (int i = 0; i < cidx; i++) {
		printf("%d\n", complex[i]);

	}

	return 0;
}
