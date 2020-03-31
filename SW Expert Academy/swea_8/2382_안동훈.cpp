// 오답 
#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int board[100][100];
pair<int, int> direction[4] = {{-1,0} ,{1,0} , {0,-1}, {0,1}}; // 상1 하2 좌3 우4

class info {
public:
	int x;
	int y;
	int qty;
	int dir; // dir 상1 하2 좌3 우4
};

queue<info> q;

bool cmp(info a, info b){
	if (a.qty > b.qty) return true;
    else return false;
}

void move(){
	int size = q.size();
    for(int i=0; i<size; i++){
    	int cx = q.front().x;
        int cy = q.front().y;
        int cqty = q.front().qty;
        int cdir = q.front().dir;
        int nx = cx + direction[cdir-1].first;
        int ny = cy + direction[cdir-1].second;

        board[cx][cy]--;
        if(board[nx][ny] != -1){
			board[nx][ny]++;
            q.push({nx,ny,cqty,cdir});
        }
        else if(board[nx][ny] == -1){
            board[nx][ny]++;
            cqty /= 2;
            if(cdir == 1) cdir = 2;
            else if (cdir == 2) cdir = 1;
            else if (cdir == 3) cdir = 4;
            else if (cdir == 4) cdir = 3;
            q.push({nx,ny,cqty,cdir});
        }
    }
}

void cal(){
    for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j] > 1){
                int size = q.size();
                vector<info> merge;

                while(size--){
                    info now = q.front();
                    q.pop();
                    if(now.x == i && now.y == j){
                        merge.push_back(now);
                    }
                    else q.push(now);        	
                }
                
                sort(merge.begin(), merge.end(), cmp);
                int s_dir = merge.front().dir;
                int sum = 0;
                
                for(int i=0; i<board[i][j]; i++){
					sum += merge.back().qty;
                    merge.pop_back();
                }
                
                q.push({i,j,sum,s_dir});
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
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		memset(board, 0, sizeof(board));

		info Info;

		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			cin >> Info.x >> Info.y >> Info.qty >> Info.dir;
            board[Info.x][Info.y]++; 
			q.push(Info);
		}
        
        //약품 칠하기
		for (int i = 0; i < N; i++) {
            board[i][N-1] = board[N-1][i] = board[0][i] = board[i][0] = -1;
		}
        
		for(int i=0; i< M; i++){
        	move(); //이동
            cal(); //겹치는 거 계산
        }
        
        int result = 0;
        
        while(!q.empty()){
            result += q.front().qty;
			q.pop();
		}
		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "  ";
            }
            cout <<  "\n";
		}
*/
