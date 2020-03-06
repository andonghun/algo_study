#include<bits/stdc++.h>

using namespace std;
char number[20];
char answer[20];
vector<char> num;
int n, k, max_result, numsize;

void dfs(int depth, int count){
        if (count == n){
            int result = 0;
            for(int i=0; i<numsize; i++){
                result = (result*10) + (number[i] - '0');
            }
            if (max_result < result) 
                max_result = result;
            return;
        }

        for(int i = depth; i<numsize; i++){
            for(int j = i+1; j<numsize; j++){
                if(number[i] <= number[j]){
                    char tmp = number[i];
                    number[i] = number[j];
                    number[j] = tmp;
                    dfs(i, count+1);
                    tmp = number[i];
                    number[i] = number[j];
                    number[j] = tmp;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int test_case;
	int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> number >> n;
		
        numsize = 0;
        k = 0;
        max_result = 0;

		while(number[k++]) numsize++;      

        dfs(0,0);
        
        cout << "#" << test_case << " " << max_result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
