/*  
    5660.삼성 기출 핀볼 게임
    https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo&categoryId=AWXRF8s6ezEDFAUo&categoryType=CODE&&https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo&categoryId=AWXRF8s6ezEDFAUo&categoryType=CODE&&&&
    2020-03-16
    진예진

    !미완성 코드
*/

#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int N;
int current, direction, answer, temp_answer, start_x, start_y;
bool start_flag;
vector<vector<int>> pinball(100, vector<int>(100, 0)); 
 // right: 0, left: 1, up: 2, down: 3
vector<vector<int>> rule = {{1, 2, 3, 0}, {1, 3, 0, 2},
                            {3, 0, 1, 2}, {2, 0, 3, 1},
                            {1, 0, 3, 2}};
// right, left, up, donw
vector<int> move_x = {1, -1, 0, 0};
vector<int> move_y = {0, 0, 1, -1};

struct Wormhole{
    int x1;
    int y1;
    int x2;
    int y2;
}wormhole[5];



int search(int x, int y, int direction, int score){
    int new_x = x;
    int new_y = y;

    while(true){
        current = pinball[x][y] - 1;

        // 블랙홀인 경우
        if(current == -1) return score; 
        // 자기자신으로 돌아온 경우
        else if(start_flag == true && start_x == x && start_y == y) return score;
        //웜홀을 만난 경우
        else{
            rule[current][direction];
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int temp;
    FILE *stream;

    stream = freopen("5650_sample_input.txt", "r", stdin);

    if(!stream)
        perror("freopen");


    scanf("%d", &T);

	for(test_case = 1; test_case <= T; ++test_case)
	{
        // -1 블랙홀(최대 5개). 0 빈공간
        // 1 ~ 5 블록, 6 ~ 10 웜홀(최대 5쌍)
        scanf("%d", &N);

        // init wormhole
        for(int i = 0; i < 5; i++){
            wormhole[i].x1 = -1;
            wormhole[i].x2 = -1;
            wormhole[i].y1 = -1;
            wormhole[i].y2 = -1;
        }


        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &pinball[i][j]);

                //init wormhole
                temp = pinball[i][j];
                if(temp > 5){
                    if(wormhole[temp - 6].x1 == -1){
                        wormhole[temp - 6].x1 = i;
                        wormhole[temp - 6].y1 = j;
                    }
                    else{
                        wormhole[temp - 6].x2 = i;
                        wormhole[temp - 6].y2 = j;
                    }
                }
            }
        }

        for(auto i: wormhole){
            printf("(%d %d) (%d %d)\n", i.x1, i.y1, i.x2, i.y2);
        }

        /* 입력 확인
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("%d ", pinball[i][j]);
            }
            printf("\n");
        }
        */

       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
                direction = '0';
                start_flag = false;
                start_x = i;
                start_y = j;
                // temp_answer = search(start_x, start_y, direction, 0);
                // answer = answer > temp_answer ? answer : temp_answer;
           }
       }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
