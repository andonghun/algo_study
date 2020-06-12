/*
2020-06-09 진예진
[백준 15652] https://www.acmicpc.net/problem/15652
*/

#include <stdio.h>

using namespace std;

int N, M;
int numbers[8];
int selected_arr[8];

void dfs(int index , int selected){
    // 선택한 숫자의 개수가 M을 넘으면 이때까지 선택한 숫자를 출력한다.
    if(selected == M){
        for(int i = 0; i < M; i++)
            printf("%d ", selected_arr[i]);
        printf("\n");
        return;
    }

    for(int i = index; i < N; i++){
        selected_arr[selected] = numbers[i];
        dfs(i, selected + 1);
    }
}

int main(){
    FILE *stream = freopen("S2\\2\\15651_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        numbers[i] = i+1;
    }

    dfs(0, 0);

    return 0;
}
