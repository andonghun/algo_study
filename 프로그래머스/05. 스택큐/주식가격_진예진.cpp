#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            //가격이 떨어지지 않은경우
            //printf("pricese i: %d pricese j:%d\n", prices[i], prices[j]);
        	if(prices[i] <= prices[j]){
                answer[i]++;
            }
            else{
                answer[i]++;
                break;
            }
        }
    }
    return answer;
}