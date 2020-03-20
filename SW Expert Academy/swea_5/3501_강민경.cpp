// 3501. 순환소수 짧게 표현하기


#include<iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

char quotient[100001]; // 몫
int remains[100001] = { 0, }; // 나머지

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int p, q;

	scanf_s("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
	//	memset(remains, 0, sizeof(remains));
		for (int i = 0; i < 100001; ++i) {
			remains[i] = 0;
		}
		scanf_s("%d %d", &p, &q);
	
		bool isCycle = 0; // 사이클 여부 체크
		int firstNum; // 자연수 몫
		int remainNum = p; // 나머지값
		int idx = 0;
		int start = 0; // 순환시작하는 idx값  표시

		while (remainNum) {
			
			if (idx == 0) {
				firstNum = p / q;
				if (remainNum % q) quotient[idx++] = '.';
			}
			else {
				quotient[idx] = remainNum /q +48;
			//	printf("quotient[%d], %d, c변환 %c\n", idx, remainNum / q, remainNum / q + 48);
				idx++;
				// int -> char일때 +48
			}

			remainNum = remainNum % q;
			
			if (remains[remainNum]) { // true이면
				start = remains[remainNum];
				isCycle = 1;
			}
			
			if (isCycle) break;
			else {
				remains[remainNum] = idx;
			}

			remainNum *= 10;
		}
		
		printf("#%d %d", test_case, firstNum);
		// 사이클일때
		if (isCycle) { 
			for (int i = 0; i < idx; i++) {

				if (start == i) {
					printf("(");
					for (int j = start; j < idx; j++) {
						printf("%c", quotient[j]);
					}
					printf(")");
					break;
				}
				else {
					printf("%c", quotient[i]);
				}
			}
		}
		// 사이클이 아닐때
		else {
			for (int i = 0; i < idx; i++) {
				printf("%c", quotient[i]);
			}
		}
		printf("\n");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}



/* 참고
#include <stdio.h>
#pragma warning(disable:4996)

char output[100001];
int firstNum = 0;
int rest[100001];


void init() {
	for (int i = 0; i < 100001; ++i) {
		rest[i] = 0;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	int tc = 0;
	while (tc++ < T) {
		init();
		int p, q;
		scanf("%d %d", &p, &q);

		int w = 0;
		int isCycle = 0;
		int start = 0;
		int cur = p;
		while (cur) {
			if (w == 0) {
				firstNum = cur / q;
				if(cur % q) output[w++] = '.';
			}
			else {
				output[w++] = (cur / q) + 48;
			}

			cur = cur % q;
			if (rest[cur]) {
				isCycle = 1;
				start = rest[cur];
			}

			if (isCycle) {
				break;
			}
			else {
				rest[cur] = w;
			}

			cur *= 10;
		}

		printf("#%d %d", tc, firstNum);
		if (isCycle) {
			for (int i = 0; i < w; ++i) {
				if (i == start) {
					printf("(");
					for (int j = start; j < w; ++j) {
						printf("%c", output[j]);
					}
					printf(")");
					break;
				}
				else {
					printf("%c", output[i]);
				}
			}
		}
		else {
			for (int i = 0; i < w; ++i) {
				printf("%c", output[i]);
			}
		}

		printf("\n");
	}



	return 0;
}
*/
