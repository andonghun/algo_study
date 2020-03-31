	#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int length = money.size();
    vector<int> dp1(length-1);
    vector<int> dp2(length);
    dp1[0] = money[0];
    dp1[1] = money[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    
        for(int i = 2; i < length - 1; i++){
            dp1[i] = (dp1[i-2] + money[i]) > dp1[i-1] ? (dp1[i-2] + money[i]) : dp1[i-1];
        }
    
        for(int i = 2; i < length; i++){
            dp2[i] = (dp2[i-2] + money[i]) > dp2[i-1] ? (dp2[i-2] + money[i]) : dp2[i-1];
        }
        
        answer = dp1[length-2] > dp2[length-1] ? dp1[length-2] : dp2[length-1];
    return answer;
}