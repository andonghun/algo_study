#include<stdio.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	
	for(int test_case = 1; test_case <= T; ++test_case) {
		int n, k;
		scanf("%d %d", &n, &k);

		if (n >= k) { 
			printf("#%d %d\n", test_case, k);
		} else {
			int num = 1;
			for (int i = n; i > 1; i--) {
				if (k % i == 0) {
					num *= i;
					k /= i;
				}
			}
			printf("#%d %d\n", test_case, num);
		}	
	}

	return 0;
}