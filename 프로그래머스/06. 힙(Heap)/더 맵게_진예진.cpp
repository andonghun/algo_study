#include <string>
#include <vector>
#include <queue>
#include <functional> //greater function

using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    int scoville_score;
    priority_queue<int, vector<int>, greater<int>> scoville_queue;
    
    for(auto sco:scoville){
    	scoville_queue.push(sco);
    }
    while(!scoville_queue.empty() && scoville_queue.size() > 1){
        if(scoville_queue.top() >= K) {
            //printf("break2");
            break;
        }
        scoville_score = scoville_queue.top();
        scoville_queue.pop();
        scoville_score += (scoville_queue.top() * 2);
        scoville_queue.pop();
        scoville_queue.push(scoville_score);
        answer++;
    }
    if(scoville_queue.top() < K) answer = -1;
    return answer;
}