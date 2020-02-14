#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(1) {
        pair<int, int> top = q.front();
        
        if (top.second == pq.top()) {
            if (location == top.first) {
                answer++;
                break; 
            } else {
                answer++;
                q.pop();
                pq.pop();
            }
        } else {
            q.pop();
            q.push(top);
        }
    }
    
    
    return answer;
}