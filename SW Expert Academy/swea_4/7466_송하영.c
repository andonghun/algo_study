#include <stdio.h>
int gcd(int N, int K) {
	int ret = 1;
	for (int i = N; i >= 1; i--) {
		if (K%i == 0) {
			ret *= i;
			K /= i;
		}
	}
	return ret;
}
int main(int argc, char** argv) {
	int tc, T, N, K;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K);
		if (N >= K)
			printf("#%d %d\n", tc, K);
		else
			printf("#%d %d\n", tc, gcd(N, K));
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
