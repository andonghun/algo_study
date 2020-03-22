#include<bits/stdc++.h>

using namespace std;
int N, X;
int height[22][22];

bool check_x(int st){
    bool check[N];
    memset(check, false, sizeof(check));
    
    for(int i=0; i<N-1; i++){
    	if(height[st][i] == height[st][i+1]){ // 평지
    		continue;
        }
        
        else if(height[st][i] + 1== height[st][i+1]){ // 오르막
			for(int j=i; j>i-X; j--){
                if(height[st][i+1] - 1 != height[st][j]) return false;
				if(check[j] == false) check[j] = true;
                else return false;
            }
            continue;
        }
        
        else if(height[st][i] - 1 == height[st][i+1]){ // 내리막
			for(int j=i+1; j<i+1+X; j++){
            	if(height[st][i] - 1 != height[st][j]) return false;
                check[j] = true;
            }
    	}
        else return false;
    }

	return true;    
}

bool check_y(int st){
    bool check[N];
    memset(check, false, sizeof(check));
    
    for(int i=0; i<N-1; i++){
    	if(height[i][st] == height[i+1][st]){ // 평지
    		continue;
        }
        
        else if(height[i][st] + 1== height[i+1][st]){ // 오르막
			for(int j=i; j>i-X; j--){
                if(height[i+1][st] - 1 != height[j][st]) return false;
				if(check[j] == false) check[j] = true;
                else return false;
            }
            continue;
        }
        
        else if(height[i][st] - 1 == height[i+1][st]){ // 내리막
			for(int j=i+1; j<i+1+X; j++){
            	if(height[i][st] - 1 != height[j][st]) return false;
                check[j] = true;
            }
    	}
        else return false;
    }

	return true;    
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

        cin >> N >> X;
        memset(height, 0, sizeof(height));
        
        for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
                cin >> height[i][j];       
    		}
    	}
        
        int cnt = 0;
        
        for(int i=0; i<N; i++){
            if(check_x(i)) cnt++;
            if(check_y(i)) cnt++;
        }
        
		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;
}
