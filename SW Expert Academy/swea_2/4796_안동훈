#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int mt[50000];
    int test_case;
	int T, N;
    queue<int> top;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int cnt = 0;
        cin >> N;
     	for(int i=0; i<N; i++){
        	cin >> mt[i];
        }
        
        for(int i=1; i<N-1; i++){
        	if(mt[i-1] < mt[i] && mt[i] > mt[i+1]) top.push(i);
        }
		//우뚝 선 지점 큐에 추가       
        
        while(!top.empty()){
         	int left = 0;
            int right = 0;
            int p = top.front();
            int left_top = mt[p];
            int right_top = mt[p];
            
            top.pop();
            
            for(int i = p - 1; i >= 0; i--){
             	if(left_top > mt[i]){
                	left++;
                    left_top = mt[i];
                }
				else break;
            }
            
            for(int j = p + 1; j < N; j++){
            	if(right_top > mt[j]){
                    right++;
                	right_top = mt[j];
                }
                else break;
            }
		cnt += right * left;
        }
        
        cout << "#" << test_case << " " << cnt << '\n';
        fill(mt, mt+N, 0);
    }
	return 0;
}
