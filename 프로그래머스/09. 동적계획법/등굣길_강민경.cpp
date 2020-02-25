#include <string>
#include <vector>

using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[110][110] = {0,};
    
    // 세로
    for(int i=0; i<=n; i++){
        dp[i][1] = 1;
    }
    // 가로
    for(int i=0; i<=m; i++){
        dp[1][i] = 1;
    }
    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
         
            // 집
            if(i == 1 && j ==1 ) continue;
            
            // 웅덩이
            if(dp[i][j] == -1){
                dp[i][j] = 0; // 0으로 변경, 1,000,000,007으로 나누어야되기 때문
            }else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] ) %  1000000007;
            }
        }   
    }
    return dp[n][m];
}
