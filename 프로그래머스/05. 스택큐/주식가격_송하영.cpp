#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    int size = prices.size()-1;
    for(int i=0;i<=size;i++){
        answer[i] = size - i;
        for(int j=i+1;j<=size;j++){
            if(prices[j]<prices[i]){
                answer[i] = j-i;
                break;
            }
        }
    }
    return answer;
}
