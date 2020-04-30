#include<bits/stdc++.h>

using namespace std;

int N, L, answer;
bool check; // 조합 가능한지 여부
int target[6] = { 2, 1, 1, 1, 1, 1 }; // S 2 A 1 M 1 U 1 N 1 G 1
int now[6];
int score[10]; // 면접관의 점수
char name[10][10]; // [idx][word]

void add(int idx, int word) {
	if (name[idx][word] == 'S') {
		now[0]++;
	}
	else if (name[idx][word] == 'A') {
		now[1]++;
	}
	else if (name[idx][word] == 'M') {
		now[2]++;
	}
	else if (name[idx][word] == 'U') {
		now[3]++;
	}
	else if (name[idx][word] == 'N') {
		now[4]++;
	}
	else if (name[idx][word] == 'G') {
		now[5]++;
	}
}

void remove(int idx, int word) {
	if (name[idx][word] == 'S') {
		now[0]--;
	}
	else if (name[idx][word] == 'A') {
		now[1]--;
	}
	else if (name[idx][word] == 'M') {
		now[2]--;
	}
	else if (name[idx][word] == 'U') {
		now[3]--;
	}
	else if (name[idx][word] == 'N') {
		now[4]--;
	}
	else if (name[idx][word] == 'G') {
		now[5]--;
	}
}

bool checker() { // now 배열에 있는 요소들이 target의 배열에 있는 요소들보다 크면
	for (int i = 0; i < 6; i++) {
		if (target[i] > now[i]) return false;
	}

	return true;
}

void dfs(int idx, int pos, int sum_score) { // idx 면접관
	if (idx == N && !checker()) return;
	if (checker()) {
//		memset(now, 0, sizeof(now));
		check = true;
		answer = min(answer, sum_score);
		return;
	}

	for (int i = pos; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			add(i, j);
		}
		dfs(idx + 1, i + 1, sum_score + score[i]);
		for (int j = 0; j < 10; j++) {
			remove(i, j);
		}
	}
}

int solve() {
	answer = 987654321;
	check = false;

	dfs(0, 0, 0);

	if (!check) return -1;
	else return answer;
}

void init() {
	memset(score, 0, sizeof(score));
	memset(name, 0, sizeof(name));
	memset(now, 0, sizeof(now));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L;
		for (int j = 0; j < L; j++) {
			cin >> name[i][j];
		}
		cin >> score[i];
	}
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
		cout << "#" << test_case << " " << solve() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
