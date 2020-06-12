/*
2020-06-11 진예진
[BJ 2667] https://www.acmicpc.net/problem/2667
*/

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N;
int num_of_houses;
int complex[25][25];
// 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool visited[25][25];

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

bool boundary_check(Coord coord){
    if(coord.x < 0 || coord.x >= N || coord.y < 0 || coord.y >= N) return false;
    else return true;
}

void grouping(Coord current_house, int group_number, int house_cnt){
    visited[current_house.y][current_house.x] = true;
    num_of_houses = house_cnt > num_of_houses? house_cnt : num_of_houses;

    for(int i = 0; i < 4; i++){
        Coord new_house = {current_house.x + dx[i], current_house.y + dy[i]};

        if(boundary_check(new_house)) grouping(new_house, group_number, house_cnt + 1);
    }
}

int main(){
    FILE *stream = freopen("S2\\2\\2667_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    priority_queue<int, vector<int>, cmp> houses;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &complex[i][j]);
        }
    }

    int grouping_number = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 좌표, 
            if(!visited[i][j] && complex[i][j] == 1) grouping(Coord(j, i), ++grouping_number, 0);
            houses.push(num_of_houses);
        }
    }

    printf("%d\n", grouping_number);
    while(!houses.empty()){
        printf("%d\n", houses.top());
        houses.pop();
    }

    return 0;
}
