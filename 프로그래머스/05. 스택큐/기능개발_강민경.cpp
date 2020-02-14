#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> pr;
    queue<int> sp;
    
    for(int i=0; i<progresses.size(); i++){
        pr.push(progresses[i]);
        sp.push(speeds[i]);
    }
    
    int day = 1;

    while(!pr.empty()){
        int finish = 0;
        int i = sp.size();
        
        for(int j = 0; j < i; j++){
            if(pr.front() + (sp.front() * day) >= 100){
                finish++;
                pr.pop();
                sp.pop();
            }
        }
        day++;
        if(finish !=0) answer.push_back(finish);
    }
    return answer;
}
