#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

	int test_case;
	int T;
    long long n, a, b;
    long long result;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> a >> b;

        result = (b-a)*(n-2)+1;// b(n-2) - a(n-2) 예외 1개
        
        if( a > b || (n == 1 && a !=b) ){
        	result = 0;
        }
        
        
        cout << "#" << test_case << " " << result << '\n';
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
