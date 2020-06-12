// https://www.acmicpc.net/problem/15652
//  15652 n과m(4)

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

	// 직전에 넣은 숫자보다 같은 숫자는 괜찮지만 작은숫자는 나오면 안됨
	for (int i = (cnt == 0) ? 1 : numbers[cnt - 1]; i <= n; i++) {
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
