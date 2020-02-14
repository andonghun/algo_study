#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
    int answer = 0, worst;
    bool flag = false;
    while(!pq.empty()&&(worst = pq.top())<K){
        pq.pop();
        if(pq.empty()){
            if(flag)
                return answer + 1;
            else
                return -1;
        }
        if((pq.top()<<1) + worst<K) pq.push((pq.top()<<1) + worst);
        else                        flag = true;
        ++answer;
        pq.pop();
    }
    return answer;
}
