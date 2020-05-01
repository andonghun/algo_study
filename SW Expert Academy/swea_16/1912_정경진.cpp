// 백준 1912. 연속합
#include <iostream>
#include <algorithm>

int testcase;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans = 0;
    cin >> n;
    int arr[n];
    int dp[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    ans = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";
    return 0;
}
