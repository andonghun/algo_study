/*
백준 11866.요세푸스 문제
난이도 실버 4
진예진 2020-04-02
https://www.acmicpc.net/problem/11866
*/

#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
    int N, K;
    int order = 1;
    int check_end = 0;
    FILE *stream;

    stream = freopen("SWEA\\9_LINE\\11866_input.txt", "r", stdin);

    if(!stream)
        printf("freopen ");

    scanf("%d %d", &N, &K);

    // 사람이 있으면 true, 없으면 false
    vector<bool> people(N, true);

    printf("<");

    for(int idx = 0; idx < N; idx++){
        // printf("%d ", idx);
        if(check_end > N - 1) break;
        if(people[idx] == true){
            if(order == K){
                printf("%d, ", idx + 1);
                order = 1;
                people[idx] = false;
                check_end++;
            }
            else{
                order ++;
            }
        }        
        idx = idx == N-1 ? -1: idx;
    }
    printf("\b\b");
    printf(">");
    return 0;
}
