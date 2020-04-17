#include <bits/stdc++.h>
using namespace std;
//15746로 나눠야함
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int dp[1000001];
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= 15746;
    }
    cout << dp[n];

    return 0;
}
