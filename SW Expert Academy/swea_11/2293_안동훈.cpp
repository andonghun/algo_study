//참고: 이해하기 힘듬 https://debuglog.tistory.com/78
#include <bits/stdc++.h>
using namespace std;

int d[10001]; //i의 가치를 가지게 만드는 모든 경우의 수

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    int coin[101];
	d[0] = 1; // 가치가 0인 경우는 모든 동전을 사용하지 않는 경우이므로 자명함
    cin >> n >> k;
    
    for(int i=1; i<=n; i++) cin >> coin[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
        	if(j-coin[i]>=0) d[j] += d[j-coin[i]];
        }
    }
    
    cout << d[k];

    return 0;
}

//메모리 초과
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    int coin[101];
    int dp[101][10001]; //i개를 사용하고, j만큼의 총 가치를 지니는 모든 경우의 수
    
    cin >> n >> k;
    
    for(int i=1; i<=n; i++) cin >> coin[i];
    
    for(int i=1; i<=k; i++) dp[i][0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j-coin[i] >= 0) dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]]; // i번째 동전을 사용하지 않고 j가치를 만드는 경우와, i번째 동전을 사용하지 않고 j-coin[i]가치를 만드는 두가지의 합
			else dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[n][k];

    return 0;
}
