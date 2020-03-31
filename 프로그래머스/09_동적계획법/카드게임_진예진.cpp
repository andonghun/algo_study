#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    vector<vector<int>> dp(left.size() + 1, vector<int>(right.size() + 1, 0));
    
    
    for(int i = 0; i <= left.size(); i++){
        for(int j = 0; j <= right.size(); j++){
            //printf("(%d, %d): ", i, j);
            if(left[i] > right[j]) {
                //printf("1\n");
                dp[i][j+1] = dp[i][j] + right[j];
            }
            else if(i != 0 && dp[i-1][j-1] != -1) {
                //printf("2: [i-1][j]: %d\n", dp[i-1][j]);
                dp[i][j+1] = dp[i-1][j] > dp[i-1][j+1] ? dp[i-1][j] : dp[i-1][j+1];
            }
            else {
                //printf("3\n");
                dp[i][j+1] = -1;
                break;
			}
        }
    }

    /*
    for(int i = 0; i <= left.size(); i++){
        for(int j = 0; j <= right.size(); j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    
    answer = dp[left.size()][right.size()];
    return answer;
}