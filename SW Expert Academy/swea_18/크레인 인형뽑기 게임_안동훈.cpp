//https://programmers.co.kr/learn/courses/30/lessons/64061
//크레인 인형뽑기 게임

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    for(int i=0; i<moves.size(); i++){
        int target = moves[i]-1;
        for(int j=0; j<board[0].size(); j++){
            if(board[j][target] == 0) continue;
            else{
                if(basket.empty()){
                    basket.push(board[j][target]);
                }
                else if(!basket.empty()){
                    if(basket.top() == board[j][target]){
                        answer += 2;
                        basket.pop();
                    }
                    else basket.push(board[j][target]);
                }
                board[j][target] = 0;
                break;
            }
        }
    }
    
    return answer;
}
