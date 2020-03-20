// 8998. 세운이는 내일 할거야

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> homework;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case;
	int T;
	int n;
	cin >> T;

	int maxday = 1000000000;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<pair<int, int>> homework;
		int data;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b; // a: 걸리는 시간 , b 마감일
			cin >> a >> b;
			homework.push_back(make_pair(b, a));
		}

		sort(homework.begin(), homework.end());

		// 마감일이 제일 늦은 과제
		// homework (8,2) (10, 3) (13, 1)
		// maxday(최대시작일) = 13 - 1 =12
		maxday = homework.back().first - homework.back().second;
		homework.pop_back();

		while (!homework.empty()) {

			int start = homework.back().first - homework.back().second; // 시작해야하는 날짜
			int end = homework.back().first; // 마감일

			homework.pop_back();

			// 현재 최대시작일과 마감날짜가 겹치는 경우
			if (maxday <= end) {
				maxday = start - (end - maxday); // 겹치는 날짜만큼 빼준다
			}
			else {
				maxday = start;
			}
		}

		printf("#%d %d\n", test_case, maxday);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
