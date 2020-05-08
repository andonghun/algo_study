#include <string>
#include <vector>
#include <stack>

using namespace std;

bool boom(int a, int b){
    return a == b;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int q_front = 0;
    stack<int> basket;
    
    for(auto move:moves){
        move = move - 1;
        for(int depth = 0; depth < board.size(); depth++){
        	if(board[depth][move] != 0){
                // printf("hit: %d, %d: ", depth, move);
                // 바구니가 비어있지 않으면
                if(!basket.empty()){
                    q_front = basket.top();
                    // printf("front[ %d ] board[ %d ] ", q_front, board[depth][move]);
                	if(q_front != board[depth][move]){
                        basket.push(board[depth][move]);
                    }
                    else{
                        basket.pop();
                        answer += 2;
                        // printf("boom");
                    }
                }
                else basket.push(board[depth][move]);
                board[depth][move] = 0;
                // printf("\n");
                break;
            } 
        }
    }
    return answer;
}
