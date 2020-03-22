#include<bits/stdc++.h>

using namespace std;

int N;
int mmap[102][102];
int hour[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    hour[1][1] = 0;
   
    while(!q.empty()){
	    auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(mmap[nx][ny] == -1) continue;
            if(hour[nx][ny] > mmap[nx][ny] + hour[cur.first][cur.second]){
                    hour[nx][ny] = mmap[nx][ny] + hour[cur.first][cur.second];
                    q.push(make_pair(nx, ny));
            }
        }
    }
    return;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T;
    string s;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        memset(mmap, -1, sizeof(mmap));
        memset(hour, 1000000, sizeof(hour));
        
        for(int i=1; i<=N; i++){
        	cin >> s;
            for(int j=0; j<N; j++){
            	mmap[i][j+1] = s[j] - 48;
            }
        }
        
        bfs(1,1);
        
        cout << "#" << test_case << " " << hour[N][N] << '\n';
	}
	return 0;
}