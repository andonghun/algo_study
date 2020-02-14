#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> priority_q;
    queue<pair<bool,int>> pair_q;
    
    for(int i = 0; i < priorities.size(); i++){
        if(location == i){
        	pair_q.push(make_pair(true, priorities[i]));
        }
        pair_q.push(make_pair(false, priorities[i]));
        priority_q.push(priorities[i]);
    }
    
    int order = 0;
    
    while(!pair_q.empty()){
        // 인쇄가 되는 경우
        if(priority_q.top() == pair_q.front().second){
            // 인쇄가 되고 타겟값인경우
            if(pair_q.front().first == true){
                answer = order+1;
                break;
            }
            //printf("%d %d\n", priority_q.top(), pair_q.front().second);
            pair_q.pop();
            priority_q.pop();
            order++;
        }
        //인쇄가 되지 않는 경우
        else{
            pair_q.push(pair_q.front());
            pair_q.pop();
        }
    }
    return answer;
}