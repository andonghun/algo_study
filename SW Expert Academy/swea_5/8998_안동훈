#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T, d1, t1, N;
    vector<pair<int, int>> dt;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> t1 >> d1;
        	dt.push_back(make_pair(d1, d1-t1));
    	}
        
        sort(dt.begin(), dt.end());
        int start = dt.back().second;
        dt.pop_back();
        
        while(!dt.empty()){
        	int st = dt.back().second;
            int ed = dt.back().first;
            
            if(start <= ed){
            	start = st - (ed-start);
            }
            else start = st;
			dt.pop_back();            
        }
        
		cout << "#" << test_case << " " << start << '\n';
	}
	return 0;
}
