#include <stdio.h>
#include <stdlib.h>

int compare(const void *A, const void *B) {
	return *(int*)A > *(int*)B ? 1 : -1;
}
int main(void) {
	int T, tc = 0,N,K,n,ans,cur;
	int v[1000];
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		int f , e;
		for (int i = 0; i < N; ++i)
			scanf("%d", &v[i]);
		qsort(v, N, sizeof(int), compare);
		f = e = ans = cur = 0;
		for(; e < N; ++e){
			if (v[e] - v[f] <= K) {
				++cur;
				ans = ans > cur ? ans : cur;
			}
			else {
				while (v[e] - v[f] > K && f < N)
					--cur, ++f;
				--e;
			}
		}
		printf("#%d %d\n", ++tc, ans);
	}
	return 0;
}
