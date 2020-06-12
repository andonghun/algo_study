//DFS�� �ذ�
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> permu;
void In()
{
	cin >> N >> M;
}
void dfs(int size) {
	//������ ��������
	if (size == M) {
		vector<int>::iterator iter;
		for (iter = permu.begin(); iter != permu.end(); iter++)
			cout << *iter << ' ';
		cout << '\n';
		return;
	}

	//����
	int tp;
	if (permu.size() == 0)
		tp = 1;
	else
		tp = permu.back();//������ �񳻸����� �����ϰ� �ϱ� ���� �۾�
	for (; tp <= N; tp++) {
		permu.push_back(tp);
		dfs(size + 1);
		permu.pop_back();
	}

}

int main() {
	In();
	dfs(0);
}