#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;
    for (int i = 0; i < progresses.size(); i++) {
        int day = (99-progresses[i])/speeds[i] + 1;
        q.push(day);
    }

    int cnt = 1;
    int top = q.front();
    q.pop();
    
    while(!q.empty()) {
        if (q.front() > top) {
            answer.push_back(cnt);
            top = q.front();
            cnt = 1;
            q.pop();
            
        } else {
            cnt++;
            q.pop();
        }
        
    }

    answer.push_back(cnt);


    return answer;
}