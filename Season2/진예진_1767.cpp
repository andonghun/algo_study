/*
2020-06-01 진예진
[SWEA 1767 프로세서 연결하기] https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf&categoryId=AV4suNtaXFEDFAUf&categoryType=CODE
참고 https://algornote.tistory.com/36
*/

#include <stdio.h>
#include <vector>
#define CORE 1
#define WIRE 2

using namespace std;

typedef struct{
    int x, y;
    bool is_on_the_wall;
}Core;

int T, N;
int least_length;
int best_connected;
int processor[12][12];
// 상, 우, 하, 좌
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<Core> cores(12);

// is_set: 전선을 놓는 거면 true
bool set_wire(int x, int y, int direction, int& local_wire_length, int length_to_remove, bool is_set){
    // 연결된 전선의 길이
    int length_connected = 0;
    while(true){
        y = y + dy[direction];
        x = x + dx[direction];

        // 범위 벗어나면 break;
        if(x < 0 || y < 0 || x > N - 1 || y > N -1) break;

        // 전선을 놓는 상황
        if(is_set == true){
            if(processor[y][x] == CORE || processor[y][x] == WIRE) return false;
            processor[y][x] = WIRE;
            local_wire_length = ++length_connected;
        }
        // 전선을 지우는 상황
        else if(is_set == false){
            if(length_connected == length_to_remove) return false;
            processor[y][x] = 0;
            local_wire_length = ++length_connected;
        }
    }
    return true;
}


// index: 코어의 인덱스, connected: 몇개나 연결되었는지, wire_length: 현재까지 연결된 와이어의 길이
void connect_wire(int index, int connected, int wire_length){
    // 모든 코어를 순환하였을 때 전선의 길이 구함
    // 연결된 코어의 수가 많고 길이가 더 길 경우
    if(index == cores.size()){
        if(connected > best_connected){
            best_connected = connected;
            least_length = wire_length;
        }
        // 연결된 코어의 수가 같으면 와이어의 길이가 더 짧은 것으로 저장한다.
        else if(connected == best_connected)
            least_length = wire_length < least_length? wire_length: least_length;
        return;
    }

    // 벽에 닿아있는 경우 검사 필요없이 다음 코어
    if(cores[index].is_on_the_wall == true) connect_wire(index + 1, connected + 1, wire_length); 

    // 그 외의 경우 상우하좌 순으로 탐색
    else{
        // 연결이 몇 번 실패했는지 셈
        int connect_fail = 0;
        for(int i = 0; i < 4; i++){
            // local_wire_length: 새롭게 연결된 전선의 길이
            int local_wire_length = 0;
            // set_wire로 전선이 놓아지면 다음 코어로 넘어감
            if(set_wire(cores[index].x, cores[index].y, i, local_wire_length, 0, true) == true)
                // 연결이 되었으니 새로 연결된 와이어 + 이전 와이어 길이
                connect_wire(index + 1, connected + 1, local_wire_length + wire_length);
            
            // 실패할 경우 fail++
            else connect_fail++;
            
            // 전선 되돌려 놓기
            set_wire(cores[index].x, cores[index].y, i, local_wire_length, local_wire_length, false);
        }
        // 4번 실패하면 4방향 모두 막힌걸로 간주하고 다음 코어로 넘어간다.
        // 이거를 안해주면 무슨 차이지??? 하나라도 연결이 됐을 때는 실행이 안되도 되는 부분!
        // 조건 검사 없이 실행해서 이 케이스도 항상 고려해야 하는 거 아닌가?
        // 만약 현재 것을 연결 안하고 다음 껄 연결했을 때 더 많은 코어가 연결 될 수 있다던가
        if(connect_fail == 4) connect_wire(index + 1, connected, wire_length);
    }
}


int main(){
    FILE *stream = freopen("S2\\1\\1767_input.txt", "r", stdin);
    if(!freopen) perror("freoepn");

    scanf("%d", &T);

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d", &N);
        
        cores.clear();

        for(int i= 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &processor[i][j]);
                if(processor[i][j] == true){
                    // x, y, is_on_the_wall: 벽에 붙어 있는가
                    Core temp;
                    if(i == 0 || j == 0 || i == N-1 || j == N-1) temp = {j, i, true};
                    else temp = {j, i, false};
                    cores.push_back(temp);
                }
            }
        }

        least_length = 987654321;
        best_connected = 0;
        
        connect_wire(0, 0, 0);

        printf("#%d %d\n", testcase, least_length);
    }
    return 0;
}
