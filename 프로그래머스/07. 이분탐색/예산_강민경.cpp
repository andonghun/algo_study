#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 95점....
// 배열, 시작, 끝, 중간값, 이전 중간값 기억
int getBudget(vector<int> budgets, int m, int start, int end){
    
    int size = budgets.size();
    int temp = (start+end)/2; // 현재 답을 저장하는 변수
    
    bool check = false;
    
    while(start <= end){
        int mid = (start + end)/2;
        long long sum = 0;
        check = false;
        
        for(int i=0; i<size; i++){
            if(budgets[i] < mid)
                sum += budgets[i];
            else{
                check = true;
                sum += mid * (size - i);
                break;
            }
        }
    //    printf("start = %d, end = %d, mid = %d, sum = %lld\n",start, end, mid, sum);

        // 가능하지 않을 경우
        if(sum > m) end = mid -1;
        else{ // 가능할 경우
            temp = mid;
            start = mid +1;
        }
    }
    if(check) return temp;
    else return budgets[size-1];
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    
    sort(budgets.begin(), budgets.end());
    int sum = 0;
    
    // budgets 모두 더해도 M보다 작으면 budgets[size-1] 값이 상한선값
//    for(int i=0; i<budgets.size(); i++){
//        sum+= budgets[i];
//    }
//    if(sum <=M) return budgets[budgets.size()-1];
    
    answer = getBudget(budgets, M, budgets[0], budgets[budgets.size()-1]);

    return answer;
}
