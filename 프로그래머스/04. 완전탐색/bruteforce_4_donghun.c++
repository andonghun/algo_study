#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    for(int garo=3; garo<brown+red; garo++){
        if((brown+red)%garo == 0){
            int sero = (brown+red)/garo;
                if((garo-2)*(sero-2) == red){
                    answer.push_back(sero);
                    answer.push_back(garo);
                    break;
                }
        }
    }
    return answer;
}