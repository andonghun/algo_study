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
        int now = 0;
        int hire = 0;
        
        for(int i=0; i<s.size(); i++){
			if(now < i){
                hire += i - now; 
                now += (i - now) + stoi(s.substr(i,1)); // i번째에서 고용한 수 + 최소 인원 충족하니 기립 박수 치는 수 더하기
            }       
            else now += stoi(s.substr(i,1));
        }
        cout << "#" << test_case << " " << hire << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
