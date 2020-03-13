// 안 돌아감...
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	int T;
    scanf("%d", &T);
	for(int test_case = 1; test_case <= T; ++test_case) {
		int num, cnt;
		stack<int> s;

		scanf("%d", &num);
		printf("#%d ", test_case);

		// num이 한 자리이면 토끼가 승
		if (num < 10) {
			printf("B\n");
			break;
		}
		// 스택에 한 자리씩 넣어주기
		while (num) {
			s.push(num % 10);
			num /= 10;
		}

		int tmp, sum = 0;

		while (!s.empty()) {
			tmp = s.top();
			s.pop();
			if (s.empty()) break;
			if (tmp + s.top() > 9) {
				tmp += s.top();
				s.pop();
				while (tmp) {
					sum += tmp % 10;
					tmp /= 10;
				}
				s.push(sum);
				sum = 0;
			} else {
				s.pop();
				s.push(tmp + s.top());
			}
			++cnt;
		}
		// cnt 홀수(토끼 승), 짝수(앨리스 승)
		(cnt&1) ? printf("B\n") : printf("A\n");
	}
	return 0;
}
