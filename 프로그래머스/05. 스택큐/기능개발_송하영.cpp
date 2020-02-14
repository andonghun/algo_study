#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int last_day = 0;
    vector<int>::iterator it=answer.begin();
    for(int i=0;i<progresses.size();i++){
        while((progresses[i]+speeds[i]*day)<100){
            ++day;
        }
        if(day!=last_day){
            answer.push_back(1);
            last_day = day;
            ++it = answer.end()-1;
        }
        else
            ++(*it);
    }
    return answer;
}
