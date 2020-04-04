#include<bits/stdc++.h>

using namespace std;

int check(long long N, int K){
    long long cnt = 0;
    for(long long i=K; i<=N; i*=K){
        cnt += N/i;
    }
    return cnt;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    cout << min(check(N,2) - check(M,2) - check(N-M,2), check(N,5) - check(M,5) - check(N-M,5));

    return 0;
}
