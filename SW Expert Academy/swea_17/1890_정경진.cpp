// 백준 1890. 점프

#include <iostream>
#include <string>

#define MAX 100
using namespace std;

int N, ans = 0;
int map[MAX][MAX];
long long dp[MAX][MAX];

long long path() {
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != N-1 && i + map[i][j] < N)
                dp[i + map[i][j]][j] += dp[i][j];
            if (j != N-1 && j + map[i][j] < N)
                dp[i][j + map[i][j]] += dp[i][j];
        }
    }
    return dp[N-1][N-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];    
    
    cout << path() << "\n";
    return 0;
}
