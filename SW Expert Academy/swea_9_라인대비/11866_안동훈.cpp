#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N, M;
	queue<int> q;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	cout << "<";
	while (1) {
		if (q.size() == 1) {
			cout << q.front() << ">";
			break;
		}
		for (int i = 1; i < M; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front() << ", ";
		q.pop();
	}

	cout << '\n';
	return 0;
}

