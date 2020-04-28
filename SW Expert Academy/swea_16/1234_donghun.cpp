#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        string S;
        bool flag = false;
        
        cin >> N >> S;
        
        while(1){
			flag = false;
            int i;
            for(i=0; i<S.length() - 1; i++){
                 	if(S[i] == S[i+1]){
                    	flag = true;
                        break;
                    }
            }
            if(flag){
            	string front = S.substr(0, i);
                string back = S.substr(i+2);
                S = front + back;
            }
            else break;
        }
        cout << "#" << test_case << " " << S << '\n';
	}
	return 0;
}
