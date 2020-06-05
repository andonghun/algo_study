/*
2020-06-04 진예진
[SWEA 1868 파핑파핑 지뢰찾기]https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE&&&
참고 https://dheldh77.tistory.com/251
참고 https://2youngjae.tistory.com/113
*/

#include <stdio.h>
#include <string.h>

using namespace std;
/*
ios_base :: sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
*/

int T, N;
char temp_board[301][301];
int board[301][301];
bool visited[301][301];
// 위부터 시계방향
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void set_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num_mine = 0;
            // 현재 셀이 지뢰면 다음 셀, 지뢰 아니면 주변의 지뢰 개수 세서 저장
            if(temp_board[i][j] == '*'){
                board[i][j] = -1;
                continue;
            }

            for(int k = 0; k < 8; k++){
                int new_x = j + dx[k];
                int new_y = i + dy[k];
                // 바운더리 검사
                if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
                if(temp_board[new_y][new_x] == '*') num_mine++;
            }

            board[i][j] = num_mine;
        }
    }
}

void find_mine(int x, int y){
    visited[y][x] = true;
    for(int k = 0; k < 8; k++){
        int new_x = x + dx[k];
        int new_y = y + dy[k];

        // 바운더리 검사
        if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
        if(temp_board[new_y][new_x] == '*') continue;
        // 새로운 좌표의 주변에 지뢰가 없으면(0 이면) 새로운 셀 주변을 재귀적으로 탐색
        if(board[new_y][new_x] == 0) find_mine(new_x, new_y);
        // 지뢰아니고 0도 아닌 양의 정수이면 방문만 체크
        else visited[new_y][new_x] = true;
    }

}

int main(){
    FILE *stream = freopen("S2\\1\\1868_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int clicked;

    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++){

        clicked = 0;

        memset(temp_board, 0, sizeof(temp_board));
        memset(board, 0, sizeof(temp_board));
        memset(visited, false, sizeof(temp_board));
        
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%c", &temp_board[i][j]);
                if(temp_board[i][j] == '*') visited[i][j] = true;
            }
        }

        set_board();
        
        printf("1");

        // 주변의 지뢰개수가 0이어서 연쇄적으로 상쇄되어 그룹이 생성되는 셀 우선 탐색
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visited[i][j] == false && board[i][j] == 0){
                    find_mine(j, i);
                    clicked++;
                }
            }
        }

        printf("2");
        
        // 양의 정수인 셀의 개수를 센다
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(temp_board[i][j] == '*') continue;
                if(!visited[i][j]) clicked++;
            }
        }
        printf("A)");

        printf("#%d %d\n", testcase, clicked);
    }
    return 0;
}
