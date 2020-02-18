#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(vector<int> budgets, int M) {
    long long sum = 0;
	
    sort(budgets.begin(), budgets.end());
    for (int i = 0; i < budgets.size(); i++) {
        sum += budgets[i];
    }
    if (sum < M) return *(budgets.end() - 1);
	
    long long average = sum / budgets.size();
    long long sum1 = 0;
    int size = budgets.size();
    long long new_average = M / size;
	
    for (int i = 0; i < budgets.size(); i++) {
        if (budgets[i] > new_average) return new_average;
        sum1 += budgets[i];
        size--;
        new_average = (M - sum1) / size;
    }
}
