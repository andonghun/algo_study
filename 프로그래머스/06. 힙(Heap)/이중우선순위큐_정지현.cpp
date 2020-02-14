#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    deque<int> dq;
    
    for (int i = 0; i < operations.size(); i++) {
        string oper = operations[i];
        int num = stoi(oper.substr(2));
        
        if (oper[0] == 'I') {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        } else {
            if (!dq.empty()) {
                if (num == 1) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }

        }
    }

    answer[0] = !dq.empty() ? dq.back() : 0;
    answer[1] = !dq.empty() ? dq.front() : 0;


    return answer;
}