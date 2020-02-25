#include <string>
#include <vector>

using namespace std;

long long dp[80];

long long solution(int N) {
    long long answer = 0;

    dp[0] = 0;
    dp[1] = 1;

    for (long long i = 2; i <= N+1; i++) {
    	dp[i] = dp[i-1] + dp[i-2];
    }

    answer = 2*dp[N+1] + 2*dp[N];

    return answer;
}