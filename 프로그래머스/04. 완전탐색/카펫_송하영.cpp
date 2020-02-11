#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    int cell = brown+red;
    for(int y=3;y<cell/2;y++){
        if(cell%y==0&&((2*y+2*(cell/y)-4)==brown)){
            vector<int> answer;
            answer.push_back(cell/y);
            answer.push_back(y);
            return answer;
        }
    }
}
