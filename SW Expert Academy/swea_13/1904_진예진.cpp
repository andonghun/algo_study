#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> dp(1000000);
    dp.clear();

    scanf("%d", &N);

    dp.push_back(1);
    dp.push_back(2);

    for(int i = 2; i < N; i++){
        dp.push_back((dp[i-2] + dp[i-1]) % 15746);
    }

    printf("%d", dp[N-1]);

    return 0;
}
