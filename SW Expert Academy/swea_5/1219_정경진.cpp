// SWEA 1219. 길찾기 (D4)
#include <stdio.h>
#include <string.h>

int arr[100][2] = {0, };

int dfs(int n, int way) {
    if (arr[n][way] == 99)
        return 1;
    if (arr[n][way] == 0)
        return 0;
    if (dfs(arr[n][way], 0))
        return 1;
    return dfs(arr[n][way], 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    for (int T = 0; T < 10; T++) {
        int test_case, n;
        scanf("%d %d", &test_case, &n);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (!arr[x][0])
                arr[x][0] = y;
            else
                arr[x][1] = y;
        }
        printf("#%d %d\n", test_case, dfs(0, 0));
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}

