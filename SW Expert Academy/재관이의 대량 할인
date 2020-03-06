#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T, N;
    int total_price;
    int arr[100001];
	cin>>T;
	    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        total_price = 0;
        cin >> N;
        for(int i = 0; i<N; i++){
            cin >> arr[i];
	        total_price += arr[i];
        }
		
        sort(arr, arr + N, greater<int>());

		for(int i = 2; i < N; i+=3){
        	total_price -= arr[i];
        }
 
        cout << "#" << test_case << " " << total_price << '\n';
        arr[100001] = { 0 };
	}
	return 0;
}
