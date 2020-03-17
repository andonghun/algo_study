// 8888 시험 d4

#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int problem[2001] = { 0, };
int n, t, p;
vector<vector<int>> people;

int main(int argc, char** argv)
{
	int test_case;
	int test;
	cin.tie(0); cout.tie(0);

	scanf("%d", &test);

	for (test_case = 1; test_case <= test; ++test_case) {
		memset(problem, 0, sizeof(problem));

		scanf("%d %d %d", &n, &t, &p);
		getchar();   // getchar를 사용하면 입력버퍼에 \n이 남기때문에 한번더 써주어야 한다.


	//	int data;
		vector<int> temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < t; j++) {

				//		scanf("%d", &data); 시간초과
				char ch = getchar();
				getchar();
				if (ch == '0') {
					problem[j]++;
					temp.push_back(0);
				}
				else
					temp.push_back(1);
				//	temp.push_back(data);
				//	if (data == 0) problem[j]++;
			}
			people.push_back(temp);
			temp.clear();
		}

		int myidx = p - 1;
		int mygrade = 0;
		int mycount = 0;
		int myrank = 0;

		// 1. 점수 계산
		// people 배열을 -> 점수, 맞힌 문제갯수, 번호 순으로 변경 
		for (int i = 0; i < n; i++) {
			int count = 0; // 맞힌 문제 수
			int grade = 0; // 점수 누적
			for (int j = 0; j < t; j++) {
				if (people[i][j] == 1) {
					count++;
					grade += problem[j];
				}
			}
			people[i][0] = grade;
			people[i][1] = count;
			people[i][2] = i;

			if (i == myidx) {
				mygrade = people[i][0];
				mycount = people[i][1];
			}
		}

		// 2. 등수 계산
		sort(people.begin(), people.end());

		for (int i = n - 1; i >= 0; i--) {

			if (mygrade < people[i][0])
				myrank++;
			else if (mygrade == people[i][0] && mycount < people[i][1])
				myrank++;
			else if (mygrade == people[i][0] && mycount == people[i][1] && myidx > people[i][2])
				myrank++;
			else if (mygrade > people[i][0])
				break;
		}
		myrank += 1;

		printf("#%d %d %d\n", test_case, mygrade, myrank);
		people.clear();

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.

}
