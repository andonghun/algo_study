#include <stdio.h>
#include <stdlib.h>
int cus[101];
int compare(const void * A, const void * B) {
	return *(int*)A > *(int*)B ? 1 : -1;
}
int main(int argc, char** argv) {
	register int tc = 1, T, N, M, K, i, has, idx, flag;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &N, &M, &K);
		for (i = 0; i < N; i++)
			scanf("%d", cus[i]);
		qsort(cus, N, sizeof(int), compare);
		has = idx = flag = 0;
		printf("#%d ", tc++);
		if (!cus[0]) printf("Impossible\n");
		else {
			for (i = 1; i <= cus[N - 1]; i++) {
				if (!(i % M)) has += K;
				while (!(cus[idx] ^ i)) {
					has ? has-- : flag = 1;
					idx++;
				}
				if (flag)
					break;
			}
			flag ? printf("Impossible\n") : printf("Possible\n");
		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
