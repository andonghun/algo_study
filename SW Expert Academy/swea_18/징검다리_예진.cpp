#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int solution(vector<int> stones, int k) {
    int answer = 0;
    long long min_value, max_value, mid_value;
    
    min_value = *min_element(stones.begin(), stones.end());
    max_value = *max_element(stones.begin(), stones.end());
    
    while(min_value <= max_value){
        mid_value =  (min_value + max_value) / 2;
        int end_check = 0; // 연속으로 몇개의 돌이 0이 되는지 체크

        for(auto stone:stones){
            if(end_check >= k) break;
            // 돌이 0이 됨
            if(mid_value > stone){
                end_check++;
            }
            else end_check = 0;
        }
        
        // 건널 수 없다.
        if(end_check >= k ) max_value = mid_value - 1;
        // 건널 수 있다.
        else min_value = mid_value + 1;
    }
    answer = max_value;
    printf("%d %d %d", min_value, mid_value, max_value);
    return answer;
}
