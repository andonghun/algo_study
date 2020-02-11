#include <string>
#include <vector>
#include <iostream>

using namespace std;

int total;

void dfs(vector<int> &numbers, int target, int depth, int sum) {
    if (depth == numbers.size()) {
        if (target == sum) {
            total++;
        }
        return;
    }
    dfs(numbers, target, depth+1, sum+numbers[depth]);
    dfs(numbers, target, depth+1, sum-numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return total;
}