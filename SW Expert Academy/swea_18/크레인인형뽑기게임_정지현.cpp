#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;

    for (int i = 0; i < moves.size(); ++i) {
    	int idx = moves[i]-1;
    	for (int j = 0; j < board.size(); ++j) {
    		if (board[j][idx] == 0) continue;

    		if (!s.empty()) {
    			if (s.top() == board[j][idx]) {
                    answer++;
    				s.pop();
    			} else {
    				s.push(board[j][idx]);
    			}
    		} else {
    			s.push(board[j][idx]);
    		}

    		board[j][idx] = 0;
    		break;		
    	}

    }
    return answer*2;
}