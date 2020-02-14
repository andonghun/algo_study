#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer =0;
    // 우선순위 큐, 오름차순
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    for(int i=0; i<scoville.size(); i++){
        PQ.push(scoville[i]);
    }
    
    int first, second;
    
    while(PQ.top() < K){
        
        if(PQ.size() <= 1) return -1;
        
        first = PQ.top();
        PQ.pop();
        second = PQ.top();
        PQ.pop();
        
        PQ.push(first + second*2);
        answer++;
    }
    return answer;
}
