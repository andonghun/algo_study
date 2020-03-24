#include <stdio.h>
int e;
char buf[101];
void inorderCC(int n) {
	if ((n << 1) <= e) inorderCC(n << 1);
	printf("%c",buf[n]);
	if ((n << 1) + 1 <= e) inorderCC((n << 1) + 1);
}
int main(void) {
	register int T = 10, tc = 0, i, t;
	while (T--) {
		scanf("%d", &e);
		for (i = 1; i <= e; ++i) {
			scanf("%d %c", t, buf[i]);
			if ((i << 1) <= e) scanf("%d", &t);
			if ((i << 1) + 1 <= e) scanf("%d", &t);
		};
		printf("#%d ", ++tc);
		inorderCC(1);
		printf("\n");
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
