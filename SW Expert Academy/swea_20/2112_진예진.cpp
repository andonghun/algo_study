/*
SWEA 보호필름
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&categoryId=AV5V1SYKAaUDFAWu&categoryType=CODE&&&
참고 https://charm-charm.postype.com/post/3597882
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int film[13][20];
int temp[13][20];
int chemicals[13];
int T, D, W, K; // D: 두께, W: 너비, K: 합격기준
int answer = 15;

bool is_pass(){
    int AB_check;

    for(int i = 0; i < W; i++){
        AB_check = 1;
        for(int j = 0; j < D-1; j++){
            if(AB_check >= K) break;
            if(temp[j][i] == temp[j+1][i]) AB_check++;
            else AB_check = 1;
        }
        if(AB_check < K) return false;
    }
    
    return true;
}


void dfs(int depth, int count){ // count: 약품투여 횟수
    if(answer <= count) return;

    if(depth == D + 1){ // depht가
        // temp initailizing
        for(int i = 0; i < D; i++){
            for(int j = 0; j < W; j++)
                temp[i][j] = film[i][j];
        }

        for(int i = 0; i < D; i++){
            if(chemicals[i] != -1){
                for(int j = 0; j < W; j++){
                    temp[i][j] = chemicals[i];
                }
            }
        }

        if(is_pass())
            answer = min(answer, count);
        return;
    }

    // 약물을 투입할 필요가 없는 경우
    chemicals[depth] = -1;
    dfs(depth + 1, count);
    if(depth == D) return;
    
    // 약물이 A로 바꾼경우
    chemicals[depth] = 0;
    dfs(depth + 1, count + 1);
    // 약물이 B로 바꾼경우
    chemicals[depth] = 1;
    dfs(depth + 1, count + 1);
}

int main(){
    FILE *stream = freopen("SWEA\\21\\2112_input.txt", "r", stdin);
    if(!stream) printf("freopen");

    scanf("%d", &T);

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d %d %d", &D, &W, &K);

        for(int i = 0; i < D; i++){
            for (int j = 0; j < W; j++){
                scanf("%d", &film[i][j]);
            }
        }

        answer = 15; // 최대값

        dfs(0, 0);

        printf("#%d %d\n", testcase, answer);

    }
    
    return 0;
}
