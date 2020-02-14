#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K && pq.size() > 1) {
        int top = pq.top();
        pq.pop();
        
        int sco = top + (pq.top()*2);
        pq.pop();
        pq.push(sco);
        
        answer++;
    }
    
    if (pq.top() < K) return -1;
    return answer;
}