//ó���� DFS����Ž������ �õ��Ͽ��µ� ���� ������ �ð��ʰ��� �߻�-  �־��� ��� 100 C 50 ��찡 ���ͼ� �ð��ʰ��� �߻��Ѱ����� ����
//���ͳݿ��� ����Ŭ�̶� ��Ʈ�� ���  ��Ģ�� ã�Ƽ� �ܼ� for���� �̿��� ����.  -�ùķ��̼ǹ���
//�־��ǰ��  N=100�϶�,�ݺ�Ƚ��  100*100 = 10000   ���⼭ 100�� ����� ����Ŭ�� ���� �ִ��� �ƴ��� �˻��Ҷ� �ִ�� �ݺ��Ǵ� Ƚ��
//�ٽɰ��� 
//�������� ������ ��ġ�ϸ� �װ��� ����Ŭ�����̹Ƿ� �� ����Ŭ �ȿ� ���Ե� ������ ���� ������ڰ� �ȴ�.
//����Ŭ�ȿ� �ִ� ������ bool map �ȿ� �־ �̹� Ȯ�ε� ������ ������� �ʴ´�.

#include <iostream>
#include <vector>
using namespace std;
int N;
int ary[101];//��������� �ε����� 1~100 
bool map[101];//������ ��� �ε����� 1~100
void In() {
	cin >> N;
	for (int tp = 1; tp <= N; tp++)
		cin >> ary[tp];
}
void func() {


	int a;
	bool flag = false;
	vector<int> buf;

	for (int tp = 1; tp <= N; tp++) {

		if (map[tp] == false) {//����Ŭ�� �Ǹ� �ȳ� ��츸 ����


			if (flag == false)
				a = tp;
			//���۰� ������ ���� ���
			if (ary[a] == tp) {
				map[tp] = true;
				if ((int)buf.size() > 0) {
					vector<int>::iterator iter;
					for (iter = buf.begin(); iter != buf.end(); iter++)
						map[*iter] = true;
					buf.clear();//buf���� �ʱ�ȭ
				}

				flag = false;
			}
			//���۰� ������ �ٸ� ���-> ����Ŭ ����
			else {
				buf.push_back(ary[a]);
				//�ִ�� ���Ǵ� ����Ŭ�˻� Ƚ�� N
				if (buf.size() == N) {
					buf.clear();
					flag = false;
					continue;
				}
				a = ary[a];
				flag = true;
				tp--;//tp�������� ����
			}



		}
	}
}
int main() {
	In();
	func();
	//map�� �߿��� true�ΰ��� �ε�����  ���õ� �����
	
	//�������
	int cnt = 0;
	for (int tp = 1; tp <= N; tp++) {
		if (map[tp] == true)
			cnt++;
	}
	cout << cnt<<'\n';
	for (int tp = 1; tp <= N; tp++) {
		if (map[tp] == true)
			cout << tp << '\n';
	}
}