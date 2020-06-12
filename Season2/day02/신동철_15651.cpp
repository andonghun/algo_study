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
			cout<< *iter<<' ';
		cout << '\n';
		return;
	}

	//진행
	for (int tp = 1; tp <= N; tp++) {
		permu.push_back(tp);
		dfs(size + 1);
		permu.pop_back();
	}
		
}

int main() {
	In();
	dfs(0);
}