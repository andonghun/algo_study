#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int s[100001];
    int dp[100001];
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> s[i];
    }
    
    dp[1] = s[1];
    int result = dp[1];
    
    for(int i=2; i<=N; i++){
        dp[i] = max(0, dp[i-1]) + s[i];
        result = max(result, dp[i]);
    }
    
    cout << result;
    return 0;
}
