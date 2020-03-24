#include <stdio.h>
#include <memory.h>
int main(void) {
	int T, tc = 0, i, idx, flag;
	char buf[11], c;
	scanf("%d", &T);
	while (T--) {
		i = idx = flag = 0;
		memset(buf, 0, sizeof(buf));
		for (; 'A'>buf[i] || buf[i]>'Z'; buf[i] = getchar());
		do {
			buf[++i] = getchar();
		} while ('A' <= buf[i] && buf[i] <= 'Z');
		do {
			c = getchar();
			if (!flag)
				switch (c) {
				case 'B': if (buf[idx] != 'B') flag = 1;
					break;
				case 'A':
				case 'D':
				case 'O':
				case 'P':
				case 'Q':
				case 'R': if (!(buf[idx] == 'A' || buf[idx] == 'D' || buf[idx] == 'O' || buf[idx] == 'P' || buf[idx] == 'Q' || buf[idx] == 'R')) flag = 1;
					break;
				default: if (buf[idx] == 'A' || buf[idx] == 'D' || buf[idx] == 'O' || buf[idx] == 'P' || buf[idx] == 'Q' || buf[idx] == 'R' || buf[idx] == 'B') flag = 1;
					break;
				}
			++idx;
		} while ('A' <= c && c <= 'Z');
		flag || idx - 1 != i ? printf("#%d DIFF\n", ++tc) : printf("#%d SAME\n", ++tc);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
