//DFS����+BFS���� ���������� ����
// �����߾��� ����
//1. ���ܹ��� �����̼�
//2. �����̳�.size()�� (int)�� ����ȯ �̼�
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
	//���� �ȿ� �ִ��� �˻�
	if (i <= H - 1 && i >= 0 && j <= W - 1 && j >= 0) {
		
		if (i <= (int)brick_map[j].size() - 1)
			return true;
		else
			return false;
	}
	else
		return false;
}
void send_bfs(int j, int map[][12],int size) {//2�����迭���ޱ� ���� �迭�����ͻ��.


	queue<pair<int, int>> qu;
	qu.push(  pair<int,int>(brick_map[j].size() - 1, j));
	
	if (brick_map[j].size() == 0)//����ó��
		return;
	map[brick_map[j].size() - 1][j] = brick_map[j][brick_map[j].size() - 1];//�湮�� ����  brick_map���ִ� ���� �������
	
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

					//���� ���ΰ�?   , �̹� �湮�ߴ� ���ΰ�?
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
void back(int j, int map[][12]) { //��Ȥ
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
	//size==N ; ����������
	if (size == N) {
		int sum = 0;
		for (int tp = 0; tp < W; tp++)
			sum += brick_map[tp].size();
		if (sum < minv)
			minv = sum;
		return;
	}
		
	int map[15][12] = { 0, };//�����뵵 ,�̹� �湮�Ͽ����� Ȯ�� �뵵�� ����
	// ���� 0�� �ʱ�ȭ .   0 ���������� �ǹ� .    0�̿��Ǽ��ڴ� �̹̹湮���� �ǹ�

	//W��ġ�� ���ɹݺ�
	for (int j = 0; j < W; j++) {

		send_bfs(j,map,size);
		
		dfs(size + 1);
		back(j,map);//���ŵǱ� ������ ����

		memset(map, 0, sizeof(map));//back�̿��� map�ʱ�ȭ
	}

}
int main() {
	cin >> T;
	for (int tp = 1; tp <= T; tp++) {
		In();
		dfs(0);
		ansqu.push(minv);
		
		//�ʱ�ȭ
		minv = 400;
		brick_map.clear();
	}

	//�������
	int b=1;
	while (!ansqu.empty()) {
		cout << "#" << b << ' ' << ansqu.front()<<'\n';
		ansqu.pop();
		b++;
	}

}