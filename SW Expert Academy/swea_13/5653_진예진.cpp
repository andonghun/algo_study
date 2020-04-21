/*
2020-04-18 진예진
SWEA 5653. [모의 SW 역량테스트] 줄기세포배양
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo&
참고 https://yabmoons.tistory.com/223 좌표계 어떻게 잡아야 할지 몰라서 참고
*/

#include <stdio.h>
#include <vector>
#define SIZE 350

using namespace std;

typedef struct Cell
{
    /* data */
    int life; // 처음에 가진 생명력
    int timer; // 활성화 되기까지 남은 시간
    int status; // -1: dead, 0: None, 1: activation, 2: inactivation
}Cell;

Cell cells[SIZE][SIZE] = {0, };

int main(void){
    int T, N, M, K;
    const int offset = 150;
    int cor_c, cor_r;
    int scan_temp;
    int answer;
    int dy[] = {1, 0, -1, 0}; // 하, 0, 상, 0
    int dx[] = {0, 1, 0, -1}; // 0, 우, 0, 좌
    Cell cell;
    Cell *cur_cell;

    FILE *stream;
    stream = freopen("SWEA\\13\\5653_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

    scanf("%d", &T);

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d %d %d", &N, &M, &K);
        answer = 0;

        for(int r = 0; r < N; r++){
            cor_r = r + offset;
            for(int c = 0; c < M; c++){
                cor_c = c + offset;
                scanf("%d", &scan_temp);

                // 줄기세포가 있는 경우
                if(scan_temp != 0){
                    cell = {scan_temp, scan_temp, 2};
                    cells[cor_r][cor_c] = cell;
                }
            }
        }

        while(K--){
            for(int r = 0; r < SIZE; r++){
                for(int c = 0; c < SIZE; c++){
                    // dead or empty
                    if(cells[r][c].status == 0 || cells[r][c].status == -1){
                        continue;
                    }
                    // inactivation
                    if(cells[r][c].status == 2){
                        // status가 2이지만 timer 가 0 이면 활성상태로 바껴야 하는 셀임
                        if(cells[r][c].timer == 0){
                            cells[r][c].status == 1;
                        }    
                        else{ // 아닌경우 타이머시간이나 줄여주자~~
                            cells[r][c].timer--;
                        }
                    }
                    // activation
                    if(cells[r][c].status == 1){
                        cell = {cells[r][c].life, cells[r][c].life, 2};
                        for(int d = 0; d < 4; d++){
                            // 아무것도 없는 빈 셀일때만 번식
                            if(cells[r + dy[d]][c + dx[d]].status == 0){
                                cells[r + dy[d]][c + dx[d]] = cell;
                            }
                        }
                        // 활성상태였던 셀은 다음에 죽음
                        cells[r][c].status = -1;
                    }

                }
            }
        }

        // 정답 개수 세기
        for(int r = 0; r < SIZE; r++){
            for(int c = 0; c < SIZE; c++){
                if(cells[r][c].status == 1 || cells[r][c].status == 2){
                    answer++;
                }
            }
        }

        printf("#%d %d\n", testcase, answer);

    }

    return 0;
}
