#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int n = triangle.size();
    int dp[n][n];

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i-1][j]; // 첫번째 요소
            } else if (i == j) {
                dp[i][j] = triangle[i][j] + dp[i-1][j-1]; // 마지막 요소
            } else {
                dp[i][j] = max(triangle[i][j] + dp[i-1][j-1], triangle[i][j] + dp[i-1][j]);

            }
        }
    }

    for (int i = 0; i < n; i++) {
        answer = answer < dp[n-1][i] ? dp[n-1][i] : answer;
    }

    return answer;
}