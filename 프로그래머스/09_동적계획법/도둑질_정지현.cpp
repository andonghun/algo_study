#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;

    int n = money.size();
    int dp[n-1];
    int dp2[n];

    dp[0] = money[0];
    dp[1] = money[0];
    for (int i = 2; i < n-1; i++) {
    	dp[i] = max(dp[i-1], dp[i-2]+ money[i]); 
    }

    dp2[0] = 0;
 	dp2[1] = money[1];
    for (int i = 2; i < n; i++) {
    	dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }

    return max(dp[n-2], dp2[n-1]);
}