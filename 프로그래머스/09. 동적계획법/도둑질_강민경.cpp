#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int first[1000001] = {0, };
    int second[1000001] = {0, };

    int a=2, b=2;
    // 1번째 집부터
    // 0번째 선택하면 size-1 번째 선택 못함 (연결)
    first[0] = money[0];
    first[1] = money[0];
    for(int i=2; i< money.size()-1; i++){ 
        first[i] = max(first[i-1], first[i-2] + money[i]);
    }
    
    // 2번째 집부터
    second[1] = money[1]; // second[0] = 0으로 초기화때 설정함
    for(int i = 2; i<money.size(); i++){
        second[i] = max(second[i-1], second[i-2] + money[i]);
    }
    
    
    return max(first[money.size()-2], second[money.size()-1]);
}
