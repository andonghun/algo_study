//����
//BFS�� �ذ�
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int T, N;
char ary[300][300];
bool map[300][300];
int dist[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
int cnt = 0;
queue<pair<int, int>> corqu;// ����8���� ���ڰ� ���°�� ��ǥ
queue<int> qu;//�����ť
void In() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> ary[i][j];
			if (ary[i][j] == '*')
				map[i][j] = false;//�����ڸ��� false
			else
				map[i][j] = true;//�����ִ� �ڸ��� true
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
			//������ ���� ���ڸ� continue
			if (ary[i][j] == '*')
				continue;
			int tp = 0;
			//8���� �����ȿ��ִ°�? 
			for (; tp < 8; tp++) {
				//���� �ȿ� ������ �˻�.
				if (isinside(dist[tp][0] + i, dist[tp][1] + j)) {
					if (ary[dist[tp][0] + i][dist[tp][1] + j] == '*') 
						break;
				}
					//�������̸� 
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
			//�����ִ� ����̰� , ���ڰ� �ƴҰ��
			if (map[curx][cury] == true && ary[curx][cury] != '*')
			{
				map[curx][cury] = false;//�̹� Ž���Ѱɷ� ǥ��

				queue<pair<int, int>>bufqu;
				int tp = 0;
				for (; tp < 8; tp++) {
					//���� �ȿ� �ְ�
					if (isinside(dist[tp][0] + curx, dist[tp][1] + cury)) {
						//������ ���ڰ� �ϳ��� ������ break;
						if (ary[dist[tp][0] + curx][dist[tp][1] + cury] == '*') {
							break;
						}
						bufqu.push(pair<int, int>(dist[tp][0] + curx, dist[tp][1] + cury));
					}
					//�������̸� 
					else
						continue;
				}
				//������ ���ڰ� �ϳ��� ���°��
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
		
		insert_qu();//����8���� *�� ���� ��ǥ�� corqu�� ����
		bfs();//corqu�� pop��Ű�鼭 �����۾���Ű�µ�, �����۾��ѹ��� cnt�� �ϳ�����.

		//���� ������ ���ڰ� �ϳ��� �ִ°�츦 ī��Ʈ��Ŵ
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (  map[i][j] == false )
					continue;
				if (ary[i][j] == '.')
					cnt++;
			}
		qu.push(cnt);
		cnt = 0;//�ʱ�ȭ
	}

	//�������
	int a = 1;
	while (!qu.empty()) {
		cout << '#' << a << ' ' << qu.front() << '\n';
		qu.pop();
		a++;
	}
	
}