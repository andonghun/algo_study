#include<stdio.h>
#include<vector>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	scanf("%d", &T);

	for(test_case = 1; test_case <= T; ++test_case) {
		int n,m,k;
		scanf("%d %d %d", &n, &m, &k);

		int mt = 0; // 가장 늦게 도착한 손의 시간
		vector<int> v(11112, 0);
		int flag = true;

		for (int i = 0; i < n; i++) {
			int time; 
			scanf("%d", &time);

			if (mt < time) mt = time; 
			if (time < m) flag = false;

			v[time]++;
		}

		// m보다 빠른 도착 시간이 없으면
		if (flag) {
			int total = 0; // 붕어빵 갯수
			
			for (int i = 0; i <= mt; i++) {
				if (i != 0 && i % m == 0) {
					total += k;
				}

				total -= v[i];

				if (total < 0) {
					flag = false;
					break;
				}
			}

		}
		
		printf("#%d %s\n", test_case, flag ? "Possible" : "Impossible");

	}

	return 0;
}