#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int testcase, T;
    int N, K; // N: 다이아 개수, K: 다이아의 가능한 최대 차
    int temp, difference, cnt, max_cnt;
    vector<int> diamond(1000);
    FILE *stream;

    stream = freopen("SWEA\\8\\9088_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

    scanf("%d", &T);

    for(testcase = 1; testcase <= T; testcase++){
        diamond.clear();

        scanf("%d %d", &N, &K);

        for(int i = 0; i < N; i++){
            scanf("%d", &temp);
            diamond.push_back(temp);
        }

        sort(diamond.begin(), diamond.end());

        max_cnt = 0;

        for(int i = 0; i < N; i++){
            cnt = 1; 
            for(int j = i+1; j < N; j++){
                difference = diamond[j] - diamond[i];
                // printf("diff: %d\n", difference);
                if(difference <= K){
                    cnt ++;
                }
                else{
                    break;
                }
                max_cnt = cnt > max_cnt ? cnt : max_cnt;
            }
        }
        printf("#%d %d\n", testcase, max_cnt);
    } 

    return 0;
}
