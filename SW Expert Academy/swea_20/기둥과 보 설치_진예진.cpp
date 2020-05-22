#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> structure(100, vector<int>(100, -1));

int cmp(vector<int> list_a, vector<int> list_b){
    if(list_a[0] == list_b[0]){
        if(list_a[1] > list_b[1]) return false;
    }
    else if(list_a[0] > list_b[0]) return false;
    else return true;
}

bool is_available(int is_beam, int x, int y){
    //printf("(%d, %d): ", y, x);
    if(is_beam == -1) return true;
 	// 기둥인 경우
    else if(is_beam == 0){
        // 바닥 위(y좌표가 0)
        if(y == 0){
            //printf("1\n");
            return true;
        }
        // 보의 한쪽 끝 부분 위, 둘 중의 한 부분만 보가 있어야 함
        else if(structure[y][x-1] == 1 || structure[y][x+1] == 1){
           	//printf("2\n");
            return true;
        }// 다른 기둥 위
        else if(structure[y-1][x] == 0){
            //printf("3\n");
            return true;
        }
    }
    // 보인경우
    else if(is_beam == 1){
        // 한쪽 끝 부분이 기둥 위
        if(structure[y-1][x] == 0 || structure[y-1][x+1] == 0){
            //printf("4\n");
            return true;
        }
        // 양쪽 끝 부분이 다른 보와 동시에 연결
        else if(structure[y][x-1] == 1 && structure[y][x+1] == 1){
            //printf("5\n");
            return true;
        }
    }
    //printf("%d %d\n", structure[y-1][x], structure[y-1][x+1]);
    for(int i = 4; i >= 0; i--){
        for(int j = 0; j < 5; j++){
            //printf("%d ", structure[i][j]);
        }
        //printf("\n");
    }
    //printf("false\n");
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    // [x, y, a, b] a: 구조물 종류(0: 기둥, 1: 보), b: 삭제할지 설치할지 여부(0: 삭제, 1: 설치)
    for(auto frame : build_frame){
        int x = frame[0];
        int y = frame[1];
        bool delete_check = true;
        
        // 삭제인 경우
        if(frame[3] == 0){
        	structure[y][x] = -1;
            //printf("삭제\n");
            for(int i = 0; i < n; i++){
                for(int j = 1; j < n-1; j++){
                    if(is_available(structure[i][j], j, i) == false){
                        //printf("false");
                        delete_check = false;
                        break;
                    }
                }
                if(delete_check == false) break;
            }
           	//printf("삭제 끝\n");
            
            if(delete_check == true){ // 지워야함
                //printf("지운다\n");
                for(int i = 0; i < answer.size(); i++){
                    if(answer[i][0] == frame[0] && answer[i][1] == frame[1]){
                        //printf("%d: (%d, %d)\n", i, answer[i][0], answer[i][1]);
                    	answer.erase(answer.begin()+i);
                    }
                }
            }
            else{ // 지울 수 없는 경우 다시 되돌림
                structure[y][x] = frame[2];
            }
        }
        // 설치인 경우
        if(frame[3] == 1){
            if(is_available(frame[2], x, y)){
                structure[y][x] = frame[2];
                answer.push_back({x, y, frame[2]});
            }
        }
    }
    
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}
