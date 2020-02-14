#include <string>
#include <vector>
#include <queue>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> work;
    int day;
    int count;
    bool flag;

    for(int i = 0; i < progresses.size(); i++){
        work.push(make_pair(progresses[i],speeds[i]));
    }

    while(!work.empty()){
        int cur_pro = work.front().first;
    	int cur_speed = work.front().second;
        day = (100 - cur_pro) / cur_speed;
        count = 0;
        flag = true;
        
        //올림
        if(((100 - cur_pro) % cur_speed) > 0){
            day++;
        }

        for(int i = 0; i < work.size(); i++){
            work.front().first += day * work.front().second;
            work.push(work.front());
            work.pop(); 
        }

        // 100 달성한 일이 몇개인지 세어줌
        while(flag){
            if(work.front().first >= 100){
                count++;
                work.pop();
                if(work.empty()){
                    flag = false;
                }
            }else{
                flag = false;;
            }
        }
        answer.push_back(count);
    }
    return answer;
}