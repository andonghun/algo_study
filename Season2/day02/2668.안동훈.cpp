// 숫자고르기
// DFS
// https://www.acmicpc.net/problem/2668

#include <bits/stdc++.h>
using namespace std;

int N;
int v[101];
int visited[101];
vector<int> answer;

void dfs(int idx) {
	if (visited[idx] >= 101) return;
	visited[idx]++; // 방문 표시
	dfs(v[idx]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) dfs(i);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] >= 101) answer.push_back(i);
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}
