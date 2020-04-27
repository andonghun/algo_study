#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    long long dp[101][11];
    
    //dp[n][h] 계단의 길이가 n일 때, 마지막 계단의 높이가 h일 때의 경우의 수
    /*
    dp[1][0] 없음 dp[1][1] ~ dp[1][9] = 1;
    dp[2][0] = dp[1][1]
    dp[2][1] = dp[1][0] + dp[1][2];
    ...
    dp[2][9] = dp[1][8];
    */
    
    dp[1][0] = 0;
    
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1]%1000000000;
            }
            else if(j == 9){
                dp[i][j] = dp[i-1][j-1]%1000000000;
            }
            else{
                dp[i][j] = dp[i-1][j+1]%1000000000 + dp[i-1][j-1]%1000000000;
            }
        }
    }
    
    long long answer = 0;
    
    for(int i=0; i<10; i++){
        answer += dp[n][i];
    }    
    
    cout << answer%1000000000;

    return 0;
}
