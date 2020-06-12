//DFS로 해결
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
	//만족및 종료조건
	if (size == M) {
		vector<int>::iterator iter;
		for (iter = permu.begin(); iter != permu.end(); iter++)
			cout << *iter << ' ';
		cout << '\n';
		return;
	}

	//진행
	int tp;
	if (permu.size() == 0)
		tp = 1;
	else
		tp = permu.back();//수열이 비내림차순 만족하게 하기 위한 작업
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