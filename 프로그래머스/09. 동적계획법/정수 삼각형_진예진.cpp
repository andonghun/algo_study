#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b){
    return a > b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int last_idx = triangle.size() - 1;
    vector<vector<int>> dp;
    
    // dp벡터 초기화
    for(int i = 0; i < triangle.size(); i++){
        vector<int> row(triangle[i].size());
        dp.push_back(row);
    }
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if(j == triangle[i].size() - 1) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
        }
    }
    
    sort(dp[last_idx].begin(), dp[last_idx].end(), cmp);
    answer = dp[last_idx][0];
    
    
    /*
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[i].size(); j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    
    return answer;
}