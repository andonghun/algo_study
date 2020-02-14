#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int SIZE = truck_weights.size();
    if(SIZE==1)
        return bridge_length+1;
    int answer = 1;
    queue<int> q;
    int cur_weight = truck_weights[0];
    int out_index = 0;
    int in_index = 1;
    q.push(0);
    while(1){
        if((answer-q.front())==bridge_length) {
            q.pop();
            cur_weight -= truck_weights[out_index++];
        }
        if(cur_weight + truck_weights[in_index]<=weight){
            q.push(answer);
            cur_weight += truck_weights[in_index++];
            if(in_index==SIZE)
                break;
        }
        ++answer;
    }
    return answer+bridge_length+1;
}
