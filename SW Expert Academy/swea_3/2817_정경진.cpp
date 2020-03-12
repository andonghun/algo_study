// SWEA 2817. 부분 수열의 합 (D3)
// 돌아감
#include <stdio.h>
 
int N, K;
int total, cnt;
int arr[20];

void dfs(int v, int total) {
    total += arr[v];
    if (total == K) {
        cnt++;
    }
    else if (total < K) {
        for (int i = v + 1; i < N; i++) {
            dfs(i, total);
        }
    }
    total -= arr[v];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        cnt = 0;
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < N; i++) {
            total = 0;
            dfs(i,0);
        }
        printf("#%d %d\n", test_case, cnt);
    }
}
