#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    
    // 내림차순, supplies 20, 10, 5 순으로 저장할 것
    // 최소 공급만 하기 위해서
    priority_queue<int> PQ;
    int idx = 0;
    for(int i=0; i<k; i++){
        
        if(i == dates[idx]){
            PQ.push(supplies[idx]);
            idx++;
        }
        if(stock ==0){
            stock += PQ.top();
            PQ.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}


/*
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    
    // 내림차순, supplies 20, 10, 5 순으로 저장할 것
    // 최소 공급만 하기 위해서
    priority_queue<int, vector<int>, less<int>> PQ;
    int idx = 0;
    for(int i=0; i<k; i++){
        
        if(i == dates[idx]){
            PQ.push(supplies[idx]);
            idx++;
        }
        if(stock ==0){
            stock += PQ.top();
            PQ.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}

 */
