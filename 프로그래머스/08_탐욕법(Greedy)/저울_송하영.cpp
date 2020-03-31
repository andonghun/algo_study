#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//43:34
int solution(vector<int> weight) {
    sort(weight.begin(),weight.end());
    int answer = 0;
    for(int i=0;i<weight.size();i++){
        if(answer+1<weight[i])  break;
        else answer+=weight[i];
    }
    return answer+1;
}
