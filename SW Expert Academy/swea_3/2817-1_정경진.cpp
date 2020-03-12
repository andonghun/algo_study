// SWEA 2817. 부분 수열의 합 (D3)
// 왜 안 돌아가는 지 모르겠음
#include <stdio.h>

int N, K;
int total, cnt;
int arr[20];

void dfs(int i, int total) {
    total += arr[i];
    if (total == K) {
        cnt++;
    } else if (total < K) {
        for (int j = i + 1; j < N; j++) {
            dfs(j, total);
        }
    }
    total -= arr[i];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; T++) {
        cnt = 0;
        scanf("%d %d", &N, &K);

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        
        for (int i = 0; i < N; i++) {
            total = 0;
            dfs(i, 0);
        }
        printf("#%d %d\n", test_case, cnt);
    }
}
