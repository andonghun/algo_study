#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int sticks = 0;
    for(int i=0;i<arrangement.length();i++){
        if(arrangement[i]=='('){
            if(arrangement[i+1]=='(')
                ++sticks;
            else{
                answer += sticks;
                ++i;
            }
        }
        else{
            ++answer;
            --sticks;
        }
    }
    return answer;
}
