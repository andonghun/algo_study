/* 
2020-06-01 진예진
[SWEA 벌꿀 채취] https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu
참고 https://charm-charm.postype.com/post/3534726
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

// N: 벌통의 크기 N * N, M: 선택할 수 있는 벌통의 개수, C: 꿀을 채취할 수 있는 최대 양
int T, N, M, C;
int local_benefit;
int honeycombs[10][10];
int visited[10][10];

void get_benefit(int x, int y, int selected, int total_honey, int total_benefit){
    if(total_honey > C) return;
    local_benefit = max(local_benefit, total_benefit);
    if(selected == M) return;

    // 벌통이 선택된 경우
    get_benefit(x + 1, y, selected + 1, total_honey + honeycombs[y][x], total_benefit + pow(honeycombs[y][x], 2));
    // 벌통이 선택되지 않은 경우
    get_benefit(x + 1, y, selected + 1, total_honey, total_benefit);
}


int get_honey(int x, int y){
    // M개를 선택할 수 있는지 검사를 안해도 되는가? => x가 어차피 N - M 까지 들어옴
    for(int i = 0; i < M; i++)
        visited[y][x+i] = true;
    
    local_benefit = 0;
    get_benefit(x, y, 0, 0, 0);
    int A_benefit = local_benefit;

    int B_benefit = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= N - M; j++){
            if(!visited[i][j]){
                local_benefit = 0;
                get_benefit(j, i, 0, 0, 0);
                B_benefit = max(B_benefit, local_benefit);
            }
        }
    }
    return A_benefit + B_benefit;
}


int main(){
    FILE *stream = freopen("S2\\1\\2115_input.txt", "r", stdin);
    if(!stream) perror("freoepn");

    scanf("%d", &T);

    memset(honeycombs, false, sizeof(honeycombs));

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d %d %d", &N, &M, &C);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &honeycombs[i][j]);
            }
        }

        // init
        int best_benefit = 0;
        local_benefit = 0;
        memset(visited, false, sizeof(visited));

        // 첫 번째 일꾼이 벌통을 선택하는 반복문
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= N - M; j++){
               best_benefit = max(best_benefit, get_honey(j, i));
            }
        }

        printf("#%d %d\n", testcase, best_benefit);
    }
    return 0;
}
