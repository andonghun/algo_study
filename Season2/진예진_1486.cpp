#include <stdio.h>
#include <algorithm>

using namespace std;

// N: 점원의 수, B: 탑의 높이, S: 점원들 키의 합
int T, N, B, S;
int clerks[20];
int answer;

void dfs(int index, int sum_height){
    if(index > N) return;
    if(sum_height >= B) answer = min(sum_height, answer);
    
    // 이번 점원을 선택
    dfs(index + 1, sum_height + clerks[index]);
    // 이번 점원을 선택하지 않음
    dfs(index + 1, sum_height);
}


int main(){
    FILE *stream = freopen("S2\\1\\1486_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d", &T);

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d %d", &N, &B);
        for(int i = 0; i < N; i++){
            scanf("%d", &clerks[i]);
        }

        answer = 987654321;

        dfs(0, 0);

        printf("#%d %d\n", testcase, answer-B);
    }

    return 0;
}
