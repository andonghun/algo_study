//�ùķ��̼ǹ����� �Ǵ� 
//�����̿��ؼ� ����Ž������ �ذ�.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int T, N, B;
vector<int> vec;//����Ű����
vector<int> vecbuf;//����Ű�������� ����
queue<int> qu;//�׽�Ʈ���̽��� ����
void In() {
	int a;
	cin >> N >> B;
	for (int tp = 0; tp < N; tp++) {
		cin >> a;
		vec.push_back(a);
	}
}
int combination(vector<int> *vect) {
	int len = (*vect).size();
	int min = 2147483647;
	int sum = 0;
	//������ �Ѹ��ΰ��
	if (  len == 1)
		return (*vect)[0] - B; //����Ű�� ���� B���� ũ�Ű� �����Ƿ� �̷��� ���� ����.
	
	//������ �θ� �̻��� ���
	for (int tp1 = 1; tp1 <= len; tp1++){ //����. vect���� tp1���� �� ��� 
		for (int tp3 = 1; tp3 <= (len - tp1); tp3++)
			vecbuf.push_back(0);
		for(int tp2=1 ; tp2<=tp1 ; tp2++)
			vecbuf.push_back(1);

		do {
			for(int tp2=0; tp2<len ; tp2++){
				if (sum >= B)//�߰�Ż�⹮
					break;
				if (vecbuf[tp2] == 1)
					sum+=(*vect)[tp2];
			}
			if ( (sum >= B) && (min > sum - B) )
				min = sum - B;
			sum = 0;//�ʱ�ȭ
		} while (next_permutation(vecbuf.begin(),vecbuf.end()));
		vecbuf.clear();//�ʱ�ȭ
	}
	return min;
}
int main()
{
	cin >> T;
	for (int tp1 = 0; tp1 < T; tp1++) { //�׽�Ʈ ���̽���ŭ ����
		In();
		sort(vec.begin(), vec.end(), less<int>());
		qu.push(combination(&vec));//���տ��� ���� �ּڰ��� ť�� ����
		
		vec.clear();//�ʱ�ȭ
	}
	int num = 1;
	
	//�������
	while (!qu.empty())
	{
		cout << '#' << num << ' ' << qu.front()<<'\n';
		qu.pop();
		num++;
	}
}