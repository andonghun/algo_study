#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    int find;
    int SIZE = heights.size();
    vector<int> answer(heights.size(),0);
    for(find = SIZE-2;find>=0;find--)
        if(heights[find]>heights[SIZE-1]){
            answer[SIZE-1] = find + 1;
            break;
        }
    
    for(int i=SIZE-2;i>=0;i--){
        if(heights[i]==heights[i+1])
            answer[i] = answer[i+1];
        else{
            for(find = i-1; find >= 0; find--){
                if(heights[find]>heights[i]){
                    answer[i] = find+1;
                    break;
                }
            }
        }
    }
    return answer;
}
