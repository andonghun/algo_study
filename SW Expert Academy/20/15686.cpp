/*
2020-05-14 진예진
[백준 15686] https://www.acmicpc.net/problem/15686
참고 https://jaimemin.tistory.com/1059
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
// #define INT_MAX 987654321

using namespace std;

typedef struct Coordi{
    int x, y;
}Coordi;

int N, M, temp_input;
bool visited[13];
int answer;
vector<Coordi> chicken_stores, houses;

int get_distance(Coordi a, Coordi b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// cnt: 현재까지 몇 개의 치킨집이 선택됐는지 개수

void dfs(int idx, int cnt){
    if(idx > chicken_stores.size()) return;
    if(cnt == M){
        int current_result = 0;
        for(int i = 0; i < houses.size(); i++){
            int distance = INT_MAX;
            for(int j = 0; j < chicken_stores.size(); j++){
                if(visited[j] == true)
                    distance = min(distance, get_distance(houses[i], chicken_stores[j]));
            }
            current_result += distance;
        }
        answer = min(answer, current_result);
        return;
    }

    visited[idx] = true;
    dfs(idx + 1, cnt + 1);

    visited[idx] = false;
    dfs(idx + 1, cnt);
}


int main(){
    FILE *stream = freopen("SWEA\\20\\15686_input.txt", "r", stdin);
    if(!stream) printf("freopen");

    scanf("%d %d", &N, &M);
    

    Coordi temp_coordi;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &temp_input);
            if(temp_input == 1){
                temp_coordi.x = j;
                temp_coordi.y = i;
                chicken_stores.push_back(temp_coordi);
            }
            else if(temp_input == 2){
                temp_coordi.x = j;
                temp_coordi.y = i;
                houses.push_back(temp_coordi);
            }
        }
    }

    answer = INT_MAX;
    dfs(0,0);
    printf("%d", answer); 

    return 0;
}
