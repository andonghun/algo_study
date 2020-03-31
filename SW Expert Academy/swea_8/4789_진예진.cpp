/*
4789.성공적인 공연 기획 (D3)
2020-03-28 진예진
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWS2dSgKA8MDFAVT&categoryId=AWS2dSgKA8MDFAVT&categoryType=CODE
*/
#include <stdio.h>
#include <string.h>

int main(void){
    int testcase, T;
    char clap[1001];
    FILE *stream;

    // stream = freopen("SWEA\\8\\4789_input.txt", "r", stdin);

    // if(!stream)
    //     printf("freopen");

    scanf("%d", &T);

    for(testcase = 1; testcase <= T; testcase++){
        int clapped;
        int hired = 0;

        scanf("%s", &clap);
        clapped = clap[0] - 48;

        for(int i = 1; i < strlen(clap); i++){
            if(hired + clapped < i){
                hired += i - (hired + clapped);
            }
            clapped += clap[i] - 48;
        }
        printf("#%d %d\n", testcase, hired);
    }
    return 0;
}
