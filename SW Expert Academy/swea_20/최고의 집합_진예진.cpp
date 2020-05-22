/*
[프로그래머스 최고의 집합] https://programmers.co.kr/learn/courses/30/lessons/12938?language=cpp
조합으로 풀면 시간초과가 나올 듯.
참고 https://mstst33.com/programmers-the_best_set/204/
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int quotient;
    int remainder;
    int index;
    
    if(n > s) answer.push_back(-1);
    else{
    	quotient = s / n;
        remainder = s % n;
        index = n - 1;
        answer.assign(n, quotient);
        
        for(int i = remainder; i > 0; i--)
            answer[index--]++;
    }
    return answer;
}
