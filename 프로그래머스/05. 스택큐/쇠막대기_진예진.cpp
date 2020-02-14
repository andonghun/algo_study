#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> bar_stack;
    
    for(int i =0; i < arrangement.length(); i++){
        char current = arrangement[i];
        char prev = arrangement[i-1];
        //printf("i: %d num bar: %d\n", i, answer);
        
        if(current == ')'){
            bar_stack.pop();
            //레이저인 경우
            if(prev == '('){
                //printf("laser i: %d stack_size: %d\n", i, bar_stack.size());
                answer += bar_stack.size();
            }
            //단순히 쇠막대기가 끝난 경우
            else if(prev == ')'){
                answer++;
            }
        }
        else if(current == '('){
            bar_stack.push('(');
        }
    }
    return answer;
}