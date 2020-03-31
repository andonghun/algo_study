#include <string>
#include <vector>
#include <utility>

using namespace std;

long long solution(int N) {
    // N = 80 일 경우 답은 122,611,581,443,223,182(십이만경)
    // int 표현범위 -2,147,483,648 ~ 2,147,483,647(20억) unsigned도 안됨.
    // long long 표현범위 –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
    long long answer = 0;
    long long temp = 0;
    vector<long long> dp(N + 1);
    pair<long, long> fibo = {1, 1};
    
    dp[1] = 4;
    
    for(int i = 2; i < N + 1; i++){
        dp[i] = dp[i-1] + 2 * fibo.second;
        temp = fibo.second;
        fibo.second += fibo.first;
        fibo.first = temp;
    }
    
    answer = dp[N];
        
    return answer;
}