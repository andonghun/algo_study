#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;

    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement[i] == ')') {
            s.pop();
            if (arrangement[i-1] == '(') {
                answer+=s.size();

            } else {
                answer++;
            }
        } else {
            s.push(arrangement[i]);
        }
    }
    return answer;
}