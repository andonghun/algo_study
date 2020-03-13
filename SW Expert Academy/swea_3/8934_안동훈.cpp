#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
	  int test_case;
	  int T;
    string s;

    cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
        cin >> s;
        int acount = 0;
        int bcount = 0;
        int ccount = 0;
        for(int i=0; i<s.size(); i++){
        	switch(s[i]){
              case 'a':
            	acount++;
            	break;
	            case 'b':
            	bcount++;
            	break;
			        case 'c':
            	ccount++;
            	break;
            }
        }
        
        int max_count = max(max(acount,bcount),ccount);
        int min_count = min(min(acount,bcount),ccount);
        
		if(max_count - min_count >= 2){
        cout << "#" << test_case << " " << "NO" << "\n";
        }
        else
        {
        cout << "#" << test_case << " " << "YES" << "\n";
        }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
