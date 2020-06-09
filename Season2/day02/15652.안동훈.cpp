// N과 M(4)
// 중복 조합
// https://www.acmicpc.net/problem/15652

#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
int N, M;

void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++) {
		answer.push_back(i + 1);
		dfs(i ,cnt + 1);
		answer.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	dfs(0, 0);

	return 0;
}
