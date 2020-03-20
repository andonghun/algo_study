#include<bits/stdc++.h>

using namespace std;

int way, ox;
int x, y;
int road1[100];
int road2[100];

void dfs(int start){
	if(road1[start] == 99 || road2[start] == 99) {
        ox = 1;
        return;
    }
	if(road1[start] != -1) dfs(road1[start]);
	if(road2[start] != -1) dfs(road2[start]);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case, tc;
	int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
	{
		//초기화
        memset(road1, -1, sizeof(road1));      
        memset(road2, -1, sizeof(road2));      

        cin >> tc >> way;
        
        for(int i=0; i<way; i++){
			cin >> x >> y;
            if(road1[x] == -1)
	            road1[x] = y;
            else road2[x] = y;           
        }
        ox = 0;
        dfs(0);

		cout << "#" << tc << " " << ox << '\n';
	}
	return 0;
}
