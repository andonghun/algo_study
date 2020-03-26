#include <stdio.h>
int main(void) {
	register long long T, N, tc = 0;
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &N);
		int flag = 0;
		while (N>1) {
			if (!(N & 1)) N >>= 1;
			else if (!((++N) & 1)) { flag = 1; break; }
			else N *= 3;
		}
		printf("#%d ", ++tc);
		flag ? printf("NO\n") : printf("YES\n");
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
