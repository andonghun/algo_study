//����
//�ùķ��̼ǹ����� �ľ�
//������ �̿��� ����Ž������ �ذ�.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T;//�׽�Ʈ���̽��� ��
int N, M, C;//����ũ��, ����ä�밡�ɰ��� , ���� ä���Ҽ��ִ� �ִ��
int ary[10][10];//���ܹ迭
int maxv = 0;
queue<int> qu;//�׽�Ʈ���̽��� ����
vector<int> vec;//���տ� �̿�� ����
void In()
{
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ary[i][j];
}
int combination(vector<int> *vect)
{
	vector<int>vecbuf;//������ ���� ���� ����
	int len = (*vect).size();
	int max = 0;
	int sum = 0;
	int climit = 0;
	
	for (int tp1 = 1; tp1 <= M; tp1++) { //��������, vect���� tp1���� ������ ����Ǽ� �ݺ� 
		for (int tp3 = 1; tp3 <= len - tp1; tp3++)
			vecbuf.push_back(0);
		for(int tp2= 1; tp2<=tp1; tp2++)
			vecbuf.push_back(1);
		
		do {
			for (int tp2 = 0; tp2 < len; tp2++) {
				if (vecbuf[tp2] == 1) {
					if (climit + (*vect)[tp2] > C)
						break;
					climit += (*vect)[tp2];
					sum += (*vect)[tp2] * (*vect)[tp2];
				}
			}
			if (max < sum)//max�� sum����
				max = sum;
			//�ʱ�ȭ
			sum = 0;
			climit = 0;
		} while (next_permutation(vecbuf.begin(),vecbuf.end()));
		vecbuf.clear();//�ʱ�ȭ
	}
	return max;
}
int main(int argc, char** argv)
{
	cin >> T;
	int sum1 = 0, sum2 = 0, cnt1 = 0,cnt2 = 0;
	for (int tp = 1; tp <= T; tp++)//�׽�Ʈcase���� ��ŭ ����
	{
		//�ʱ�ȭ
		In();
		sum1 = 0;
		sum2 = 0;
		cnt1 = M;
		cnt2 = M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//ù��° �ϲ�)���� N������ �ʰ��ϸ� break;
				if ( (cnt1==M) && ((j + M) > N)) {
					break;
				}
				if (cnt1!=0) {
					vec.push_back(ary[i][j]);
						cnt1--;
				}
				if (cnt1 == 0)
				{
					sort(vec.begin(), vec.end());
					sum1= combination(&vec);//ù��° �ϲ��� ������ M�� ��ŭ�� �ܿ��� ������ �ִ�ġ==sum1
					vec.clear();//�ʱ�ȭ
					for (int i2 = i; i2 < N; i2++) {//�ι�° �ϲ��� ������ �� �ִ� ����� �ݺ�.
						int j2 = 0;
						if (i2 == i)// ù���� �ϲ��� M��ŭ ������ ���� �������� �ι�° �ϲ��� ����Ű�� ���� ���ǹ�
							j2 = j+1;
						for ( ; j2 < N; j2++) {
							//�ι�° �ϲ�)���� N������ �ʰ��ϸ� break;
							if ( (cnt2==M) && ((j2 + M) > N))
								break;
							if (cnt2 != 0) {
								vec.push_back(ary[i2][j2]);
								cnt2--;
							}
							if (cnt2 == 0)
							{
								sort(vec.begin(), vec.end());
								sum2 = combination(&vec);
								if (maxv < (sum1 + sum2)) { //ù��° �ι�° �ϲ��� ���� ���� �ִ�ġ ����
									maxv = sum1 + sum2;
								}

								//�ʱ�ȭ
								vec.clear();
								cnt2 = M;
								sum2 = 0;
								j2 -= (M - 1);
							}

						}
					}
					cnt1 = M;
					sum1 = 0;
					j -= (M - 1);
				}
			}
		}
		qu.push(maxv);
		maxv = 0;
	}

	//�������
	int a = 1;
	while (!qu.empty())
	{
		cout <<'#'<<a<<' '<< qu.front();
		cout << '\n';
		qu.pop();
		a++;
	}
	return 0;
}