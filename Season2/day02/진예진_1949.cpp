/*
2020-06-11 진예진
[SWEA 1949] https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq&&
*/

#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

int N, K;
// 상, 우, 하, 좌
int dx[8] = {0, 1, 0, -1};
int dy[8] = {-1, 0, 1, 0};
int mountain[8][8];
bool visited[8][8];
int longest_path = 0;
queue<Coord> top;

bool boundary_check(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

// 등산로를 만들 수 있는지 확인하는 함수
int make_trail(int x, int y, int new_x, int new_y, int k){
    // 현재 위치
    int *current = &mountain[y][x];
    // 새롭게 등산로를 만드려는 위치
    int *new_trail = &mountain[new_y][new_x];
    int dig = 0;

    // 경사로 만들기, 가려는 위치가 더 크면 깍음
    while(*new_trail >= *current){
        if(k > dig){
            // 저장된 값에 --
            *new_trail -= 1;
            dig++;
        }
        // 더 이상 산을 깍을 수 없음
        else break;
    }

    // 등산로를 만들 수 있으면, 깍은 만큼 리턴
    if(*new_trail < *current){
        visited[new_y][new_x] = true;
        return dig;
    }
    // 등산로로 만들 수 없으면 판 거 복구하고 return -1
    else{
        *new_trail += dig;
        return -1;
    }
}

// 8방위로 등산로를 탐색하는 함수
void find_trail(int x, int y, int k, int trail_length){
    longest_path = trail_length > longest_path ? trail_length : longest_path;
    
    for(int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        int dig = -1;

        // 다음에 갈 위치를 얼마나 팔지 측정
        if(!visited[new_y][new_x] && boundary_check(new_x, new_y)) dig = make_trail(x, y, new_x, new_y, k);
        else continue;

        // 등산로를 만들 수 있는 경우
        if(dig != -1){
            find_trail(new_x, new_y, k - dig, trail_length + 1);
            // 백트래킹하면서 판 만큼 복구
            mountain[new_y][new_x] += dig;
            visited[new_y][new_x] = false;
        }
    }

}

int main(){
    FILE *stream = freopen("S2\\2\\1949_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    int T;
    int max;

    scanf("%d", &T);

    memset(mountain, 0, sizeof(mountain));

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d %d", &N, &K);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &mountain[i][j]);
                max = mountain[i][j] > max? mountain[i][j] : max;
            }
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(mountain[i][j] == max) top.push(Coord(j, i));
        
        
        longest_path = 0;
        max = 0;

        while(!top.empty()){
            memset(visited, false, sizeof(visited));
            Coord temp = top.front();
            top.pop();
            // x, y, K, 등산로의 길이
            visited[temp.y][temp.x] = true;
            find_trail(temp.x, temp.y, K, 1);
        }

        printf("#%d %d\n", testcase, longest_path);
    }
    return 0;
}
