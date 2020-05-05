/*
2020-05-04 진예진
백준 스타트와 링크 https://www.acmicpc.net/problem/14889
참고 https://wjdgus2951.tistory.com/82
*/

#include <stdio.h>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int N;
int answer = INT_MAX;
int ability[20][20];
bool check[20] = { false, };


void dfs(int player_num, int chosen){
    if(chosen == N / 2){
        int start_score = 0, link_score = 0;
        int start_x, start_y, link_x, link_y;
        vector<int> link, start;

        for(int i = 0; i < N; i++){     
            if(check[i]) start.push_back(i);
            else link.push_back(i);
        }

        for(int i = 0; i < start.size(); i++){
            for(int j = i+1; j < start.size(); j++){
                start_x = start[i];
                start_y = start[j];
                link_x = link[i];
                link_y = link[j];

                start_score += ability[start_x][start_y] + ability[start_y][start_x];
                link_score += ability[link_x][link_y] + ability[link_y][link_x];
            }
        }

        // 점수의 차 계산
        answer = min(answer, abs(start_score - link_score));
        return;
    }

    for(int i = player_num; i < N; i++){
        if(check[i] == false){
            check[i] = true;
            dfs(i, chosen + 1);
            // 여기서 다시 fasle로 바꿔주어서 백트래킹
            check[i] = false;
        }
    }
}


int main(){
    FILE *stream;
    stream = freopen("SWEA\\17\\14889_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &ability[i][j]);
        }
    }

    dfs(0, 0);
    printf("%d", answer);

    return 0;
}
