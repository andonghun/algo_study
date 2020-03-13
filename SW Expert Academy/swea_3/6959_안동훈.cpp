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
        int answer = 0;
        
        while(s.size() != 1){
        	int a = stoi(s.substr(0, 1));
          int b = stoi(s.substr(1, 1));
            
            if(a+b >= 10){
                string sum1 = to_string(a+b);
              	s.replace(0, 2, sum1);
                answer++;
            }
            else if(a+b < 10){
		        		string sum2 = to_string(a+b);
                s.erase(0, 2);
                s.insert(0, sum2);
                answer++;
            }
        
        }
        char aorb;

        if(answer%2 == 0) aorb = 'B';
        else aorb = 'A';
        
        cout << "#" << test_case << " " << aorb << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
