#include<bits/stdc++.h>

using namespace std;

int N;
string S;
int board[21][21];
int answer[21][21];
queue<int> before, after;

void solve() {
	if (S == "left") {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 0) continue; 
				else {
					before.push(board[i][j]);
				}
			}

			while(1) {
				if (before.empty()) break;
				int front = before.front();
				before.pop();
				if (before.empty()) {
					after.push(front);
					break;
				}
				if (front == before.front()) {
					before.pop();
					after.push(front * 2);
				}
				else {
					after.push(front);
				}
			}

			for (int j = 1; j <= N; j++) {
				if (after.empty()) break;
				int temp = after.front();
				after.pop();
				answer[i][j] = temp;
			}
		}
	}
	else if (S == "right") {
		for (int i = 1; i <= N; i++) {
			for (int j = N; j >= 1; j--) {
				if (board[i][j] == 0) continue;
				else {
					before.push(board[i][j]);
				}
			}

			while (1) {
				if (before.empty()) break;
				int front = before.front();
				before.pop();
				if (before.empty()) {
					after.push(front);
					break;
				}
				if (front == before.front()) {
					before.pop();
					after.push(front * 2);
				}
				else {
					after.push(front);
				}
			}

			for (int j = N; j >= 1; j--) {
				if (after.empty()) break;
				int temp = after.front();
				after.pop();
				answer[i][j] = temp;
			}
		}
	}
	else if (S == "up") {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[j][i] == 0) continue;
				else {
					before.push(board[j][i]);
				}
			}

			while (1) {
				if (before.empty()) break;
				int front = before.front();
				before.pop();
				if (before.empty()) {
					after.push(front);
					break;
				}
				if (front == before.front()) {
					before.pop();
					after.push(front * 2);
				}
				else {
					after.push(front);
				}
			}

			for (int j = 1; j <= N; j++) {
				if (after.empty()) break;
				int temp = after.front();
				after.pop();
				answer[j][i] = temp;
			}
		}
	}
	else if (S == "down") {
		for (int i = 1; i <= N; i++) {
			for (int j = N; j >= 1; j--) {
				if (board[j][i] == 0) continue;
				else {
					before.push(board[j][i]);
				}
			}

			while (1) {
				if (before.empty()) break;
				int front = before.front();
				before.pop();
				if (before.empty()) {
					after.push(front);
					break;
				}
				if (front == before.front()) {
					before.pop();
					after.push(front * 2);
				}
				else {
					after.push(front);
				}
			}

			for (int j = N; j >= 1; j--) {
				if (after.empty()) break;
				int temp = after.front();
				after.pop();
				answer[j][i] = temp;
			}
		}
	}
}

void input() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
}

void init() {
	memset(board, 0, sizeof(board));
	memset(answer, 0, sizeof(answer));
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		init();
		input();
		solve();

		cout << "#" << test_case << '\n';
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << answer[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
