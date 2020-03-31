#include<bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
	if(a.length() == b.length())
    	 return a < b;
    else return a.length() < b.length();
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
	int test_case;
	int T, N;

    cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		cin >> N;
        string s;
        vector<string> v;

        for(int i=0; i<N; i++){
            cin >> s;
			v.push_back(s);
        }

        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(),v.end()),v.end());

        cout << "#" << test_case << '\n';
        for(int i=0; i<v.size(); i++){
            cout << v[i] << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
