// https://www.acmicpc.net/problem/15651
// n과m(3)

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
int n, m;

void dfs(int cnt) {

	if (cnt == m) {
		for (int i = 0; i < numbers.size(); i++) {
			printf("%d ", numbers[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		numbers.push_back(i);
		dfs(cnt + 1);
		numbers.pop_back();
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	scanf_s("%d %d", &n, &m);

	dfs(0);

	return 0;
}


