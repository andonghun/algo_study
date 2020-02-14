#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> iron;
    
    for(int i=0; i<arrangement.size(); i++){
        if(arrangement[i] == '('){
            iron.push(1);
        }else{
            iron.pop();
            
            if(arrangement[i-1] == '('){
                answer += iron.size();
            }else
                answer++;
        }
    }
    
    return answer;
}
