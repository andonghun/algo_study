#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long sizeArr[81];
    
    sizeArr[0] = 1;
    sizeArr[1] = 1;
    
    if(N ==1){
        answer = 4;
        return answer;
    }
    
    // 현재 currentSize를 sizeArr배열에 저장
    for(int i=2; i<=N;i++ ){
        sizeArr[i] = sizeArr[i-1] + sizeArr[i-2];
    }
    
    
    long long currentSize = sizeArr[N-1];
    long long beforeSize = sizeArr[N-2];
    
    answer = currentSize *2 + (beforeSize + currentSize)*2;
    
    return answer;
}
