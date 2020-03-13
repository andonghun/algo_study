#include<bits/stdc++.h>

using namespace std;
int N, K, answer;
int arr[21];

//idx를 N까지 보면서 숫자를 더하던가, 스킵하던가
void dfs(int idx, int sum){
	if(idx == N) return;
    if(sum + arr[idx] == K) answer++;

    // 그냥 인덱스 스킵하기
    dfs(idx+1, sum);
    // 더하기
    dfs(idx+1, sum + arr[idx]);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
	int test_case;
	int T;

    cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		answer = 0;
        cin >> N >> K;
        
        for(int i=0; i<N; i++){
        	cin >> arr[i];
        }
        
        dfs(0, 0);
        
        cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
