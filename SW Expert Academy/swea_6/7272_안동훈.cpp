#include<bits/stdc++.h>

using namespace std;

int check(char word){
	int look;
    switch (word){
        case 'B':
            look = 2;
            break;
        case 'A':
            look = 1;
            break;
        case 'D':
            look = 1;
            break;
        case 'O':
            look = 1;
            break;
        case 'P':
            look = 1;
            break;
        case 'Q':
            look = 1;
            break;
        case 'R':
            look = 1;
            break;
          
            default:
            look = 0;
            break;
    }
    return look;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T;
    string s1, s2;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> s1 >> s2;
        
        int size1 = s1.size();
        int size2 = s2.size();

        if(size1 != size2) {
            cout << "#" << test_case << " " << "DIFF" << '\n';
        	continue;
        }
        
        bool change = false;
        for(int i=0; i<size1; i++){
			if(check(s1[i]) != check(s2[i])) change = true;
    	}
        
        if(change) cout << "#" << test_case << " " << "DIFF" << '\n';
		else cout << "#" << test_case << " " << "SAME" << '\n';
        
        s1.clear();
        s2.clear();
	}
	return 0;
}