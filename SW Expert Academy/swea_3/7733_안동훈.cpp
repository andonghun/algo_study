#include<bits/stdc++.h>

using namespace std;

int cheeze[102][102];
bool visit[102][102];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int max_num, answer, lump;
int N;

void bfs(int a, int b){
	queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b] = true;

    while(!q.empty()){
    	int size = q.size();
        for(int i=0; i<size; i++){
        	auto cur = q.front();
            for(int j=0; j<4; j++){
            	int nx = cur.first + dx[j];
                int ny = cur.second + dy[j];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if(visit[nx][ny] == true || cheeze[nx][ny] == 0) continue;
                q.push({nx, ny});
                visit[nx][ny] = true;                            
            }
		q.pop();        
        }
    }
}

void eat_cheeze(int day){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(cheeze[i][j] == day){
                cheeze[i][j] = 0;
            }        
        }
    }    
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
	int test_case;
	int T;

    cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		max_num = 0;
        answer = 1;
        cin >> N;

        for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
				cin >> cheeze[i][j];
                if(max_num < cheeze[i][j]){
                    max_num = cheeze[i][j];
                }
    	    }
        }
        
        for(int i=1; i<max_num; i++){
        	eat_cheeze(i);
            
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    visit[j][k] = false;
                }
            }
        
            lump = 0;            

            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    if(visit[j][k] == false && cheeze[j][k] > 0){
                        bfs(j,k);
                        lump++;
                    }
                }
            }
            answer = max(lump, answer);       
        }
        
        cout << "#" << test_case << " " << answer << "\n";
		
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
