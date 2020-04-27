#include<bits/stdc++.h>

using namespace std;

class userInfo {
public:
	int x;
	int y;
};

class bcInfo {
public:
	int x;
	int y;
	int c;
	int p;
	bool check;
};

int answer;

int M, A;
int a[101];
int b[101];
bcInfo BC[8];
userInfo user[2];
int board[11][11];
int dx[5] = { 0, -1, 0, 1, 0}; //1 상 2 하 3 좌 4 우
int dy[5] = { 0, 0, 1, 0, -1};

void init() {
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			board[i][j] = -1;

	for (int i = 0; i < A; i++) BC[i].check = false;

	user[0].x = 1; user[0].y = 1;
	user[1].x = 10; user[1].y = 10;
	answer = 0;
}

void input() {
	cin >> M >> A;

	for (int i = 0; i < M; i++) cin >> a[i];
	for (int i = 0; i < M; i++) cin >> b[i];
	for (int i = 0; i < A; i++) cin >> BC[i].y >> BC[i].x >> BC[i].c >> BC[i].p;		
}

int charge(int ax, int ay, int bx, int by) {
	int sum = 0;
	vector<int> possibleA, possibleB;
	int max_a = 0;
	int max_b = 0;
	//a와 b에 겹치는 BC부터 찾기
	for (int i = 0; i < A; i++) {
		int distFromA = abs(ax - BC[i].x) + abs(ay - BC[i].y);
		int distFromB = abs(bx - BC[i].x) + abs(by - BC[i].y);
		if (distFromA <= BC[i].c) {
			possibleA.push_back(i);
			max_a = max(max_a, BC[i].p);
		}
		if (distFromB <= BC[i].c) {
			possibleB.push_back(i);
			max_b = max(max_b, BC[i].p);
		}
	}

	if (possibleA.size() == 0)
	{
		if (possibleB.size() == 0) return 0;
		else return max_b;
	}
	
	if (possibleB.size() == 0)
	{
		if (possibleA.size() == 0) return 0;
		else return max_a;
	}

	for (int i = 0; i < possibleA.size(); i++)
	{
		int A_BC = possibleA[i];
		for (int j = 0; j < possibleB.size(); j++)
		{
			int B_BC = possibleB[j];

			if (A_BC == B_BC) sum = max(sum, BC[A_BC].p);
			else sum = max(sum, BC[A_BC].p + BC[B_BC].p);
		}
	}

	return sum;
}

int solve() {
	int ans = 0;

	ans += charge(user[0].x, user[0].y, user[1].x, user[1].y);

	for (int i = 0; i < M; i++) {
		user[0].x += dx[a[i]]; user[0].y += dy[a[i]];
		user[1].x += dx[b[i]]; user[1].y += dy[b[i]];
		ans += charge(user[0].x, user[0].y, user[1].x, user[1].y);
	}
	return ans;
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
		answer = solve();
		
		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
