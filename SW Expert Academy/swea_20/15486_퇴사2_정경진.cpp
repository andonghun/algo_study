// 백준 15486. 퇴사 2
// dp 뒤에서 부터
#include <iostream>
#include <algorithm>

#define MAX 1500000
using namespace std;

int T[MAX];
int P[MAX];
int dp[MAX+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i + T[i] > N) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], P[i] + dp[i + T[i]]);
    }

    cout << dp[0] << "\n";

    return 0;
}
