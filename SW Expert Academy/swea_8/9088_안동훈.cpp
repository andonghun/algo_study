#include<bits/stdc++.h>

using namespace std;
int size[10001];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
	int test_case;
	int T, N, K;

    cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		cin >> N >> K;
        memset(size, 0, sizeof(size));
        int max_num = 0;
		int x;
        
        for(int i=0; i<N; i++){
            cin >> x; 
            size[x]++;
        }
        
        for(int i=1; i<10000-K; i++){
			int sum = 0;
            for(int j=i; j<=i+K; j++){
				sum += size[j];
            }
            max_num = max(max_num, sum);
        }
        cout << "#" << test_case << " " << max_num << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
