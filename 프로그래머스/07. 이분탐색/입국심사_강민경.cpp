#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
   
    int size = times.size();
    long long min = 1;
    long long max = (long long)(times[size-1] )*n;
    long long answer = max;
    while(min <= max){
        long long sum = 0;
        long long mid = (min+max)/2;
        
        for(int i=0; i<size; i++){
            sum += mid/times[i];
        }
        
        // 가능하지 않은 경우
        if(n > sum) min = mid+1;
        else{ // 가능한 경우
            if(mid <= answer){
                answer = mid; // 최소값을 구하기 때문에 answer 갱신함
            }
            max = mid-1;
        }
    }
    return answer;
}
