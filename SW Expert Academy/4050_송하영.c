#include <stdio.h>
#include <stdlib.h>

int clothes[100000], N;
long answer = 0;
int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b ? 1 : -1;
}
int main(int argc, char** argv) {
    register int tc = 1;
    int T;
    scanf("%d",&T);
    for (; tc <= T;tc++) {
        scanf("%d",&N);
        for (int i = 0; i < N; i++)
            scanf("%d",&clothes[i]);
        qsort(clothes, N, sizeof(int), compare);
        for (int i = N - 1; i >= 0; i--)
            if ((N - i) % 3)
                answer += clothes[i];
        printf("#%d %ld\n",tc,answer);
    }
}
