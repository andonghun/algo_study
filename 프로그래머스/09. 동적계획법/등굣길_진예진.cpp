#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    pair<int, int> dis_cnt;
    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(m+1));
    
    //dp 배열 초기화. first => 최단거리. second => 최단거리 길의 개수
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
        	if(i == 0) dp[i][j] = {-1, -1};
            else if(j == 0) dp[i][j] = {-1, -1};
            else dp[i][j] = {0, 0};
        }
    }
    
    printf(puddles.empty() ? "true" : "false");
    printf("size: %d\n", puddles[0].size());
    
    
    //puddles 초기화 (m, n)으로 들어있으니 주의....Tlqk.........
    if(puddles[0].size() != 0){
        for(auto puddle:puddles){
            dp[puddle[1]][puddle[0]] = {-1, -1};
        }
    }
    
    dp[1][1] = {1, 1};
    
    /*
    //출력
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            printf("(%d %d) ", dp[i][j].first, dp[i][j].second);
        }
        printf("\n");
    }
    */
    
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
//            printf("(i: %d, j: %d)  ", i, j);
            // 집(1,1)에서 넘어감
            if(i == 1 && j == 1) {
//                printf("continue1\n");
                continue;
            }
            // paddle
            else if(dp[i][j].first == -1) {
//                printf("continue2\n");
                continue;
            }
            // 왼쪽 위쪽 둘 다 -1 인 경우 경로가 없으므로 똑같이 -1, -1 저장
            else if(dp[i-1][j].first == -1 && dp[i][j-1].first == -1) {
                dp[i][j] = {-1, -1};
//                printf("왼쪽 위쪽 둘다 -1\n");
            }
            // 위쪽만 -1인 경우 왼쪽 값에 거리 값만 +1 업데이트함
            else if(dp[i-1][j].first == -1){
                dp[i][j] = dp[i][j-1];
                dp[i][j].first++;
//                printf("위쪽만 -1\n");
                //printf("%p %p\n", &dp[i][j], &dp[i][j-1]);
            }
            // 왼쪽만 -1인 경우 위쪽 값에 거리 값만 +1 업데이트함
            else if(dp[i][j-1].first == -1){
                dp[i][j] = dp[i-1][j];
                dp[i][j].first++;
//                printf("왼쪽만 -1\n");
            }
            // 위쪽 왼쪽 거리가 같은 경우 두 가지 모두 더함
            else if(dp[i-1][j].first == dp[i][j-1].first){
                dp[i][j].first = ++dp[i-1][j].first;
                dp[i][j].second = dp[i-1][j].second % 1000000007 + dp[i][j-1].second % 1000000007;
//                printf("d위쪽 왼쪽 거리 같음 \n");
            }
            // 위쪽의 거리가 더 짧은 경우
            else if(dp[i-1][j].first < dp[i][j-1].first){
                dp[i][j] = dp[i-1][j];
                dp[i][j].first++;
//                printf("위쪽 짧음\n");
            }
            // 왼쪽의 거리가 더 짧은 경우
            else if(dp[i-1][j].first > dp[i][j-1].first){
                dp[i][j] = dp[i-1][j];
                dp[i][j].first++;
//                printf("왼쪽 짧음\n");
            }
//            else printf("nothing\n");
        }
    }
    
    /*
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            printf("(%d %d) ", dp[i][j].first, dp[i][j].second);
        }
        printf("\n");
    }
    */
    
    answer = dp[n][m].second % 1000000007;
    if(answer == -1) answer = 0;
    
    return answer;
}