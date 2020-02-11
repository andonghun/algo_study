#include <string>
#include <vector>

using namespace std;

int cnt;

void dfs(int idx, vector<int> numbers, int target, int sum) {
    if (idx + 1 == numbers.size()) {
        if (sum == target) {
             cnt++;
        }
        
        return;
    } 
    
    dfs(idx+1, numbers, target, sum+numbers[idx+1]);
    dfs(idx+1, numbers, target, sum-numbers[idx+1]);
}

int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    
    dfs(0, numbers, target, numbers[0]);
    dfs(0, numbers, target, -numbers[0]);
        
    int answer = cnt;
    
    return answer;
}