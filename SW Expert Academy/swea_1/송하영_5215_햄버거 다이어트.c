#include <stdio.h>
#include <memory.h>
int had[1<<20+1], N, L, answer=0, cals[20], happys[20];
void simulation(int cal, int picked, int happiness) {
    if (had[picked]) return;
    had[picked] = cal;
    answer = answer > happiness ? answer : happiness;
    for (int i = 0; i < N; i++) {
        if (picked&(1 << i)) continue;
        if (cal + cals[i] < L)		simulation(cal + cals[i], picked + (1 << i), happiness + happys[i]);
    }
}
int main(int argc, char** argv) {
    int tc, T;
    scanf("%d",&T);
    for (tc = 1; tc <= T; tc++) {
        scanf("%d %d",&N,&L);
        answer = 0;
        memset(had, 0, sizeof(had));
        for (int i = 0; i < N; i++) { scanf("%d %d",&happys[i],cals[i]);}
        simulation(0, 0, 0);
        printf("#%d %d\n",tc,answer);
    }
}
