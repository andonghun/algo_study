#include <stdio.h>
#define ll long long
int main(int argc, char** argv) {
	register int  tc = 1, T;
	scanf("%d", &T);
	ll N, min, cmp;
	while (T--) {
		min = 2; cmp = 4;
		scanf("%d", &N);
		if (!(N ^ 1)) printf("#%d Bob\n",tc++);
		else {
			while (1) {
				if (min <= N && N<min + cmp) { printf("#%d Alice\n",tc++); break; }
				min += cmp;
				if (min <= N && N<min + cmp) { printf("#%d Bob\n", tc++); break; }
				min += cmp;
				cmp <<= 2;
			}
		}
	}
}
