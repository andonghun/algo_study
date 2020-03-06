#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int answer;
string s;

void dfs(int cnt, int now) {
	if (cnt == K) {
		answer = max(answer, stoi(s));
		return;
	}

	for (int i = now; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			if (i == j)continue;
			if (s[i] <= s[j]) {
				swap(s[i], s[j]);
				dfs(cnt + 1, i);
				swap(s[i], s[j]);

			}
		}
	}
}



int main(int argc, char** argv)
{
	int test_case;
	int T;

	vector<int> number;
	int temp;
	string input;
	char tmp[256];

	// freopen("input.txt", "r", stdin);
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		//cin >> temp;
		// input = to_string(temp);
		cin >> s;
		cin >> K;

		answer = 0;
		dfs(0, 0);

		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
