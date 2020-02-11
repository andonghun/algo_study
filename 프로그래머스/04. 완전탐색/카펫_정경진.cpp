#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int getBrown(int a, int b) {
    return 2 * ((a + 2) + b);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> solution(int brown, int red) {
    int val1 = sqrt(red);
    int val2 = red / val1;
    cout << val1 << " " << val2 << endl;
    
    while (brown != getBrown(val1, val2)) {
        val1 -= 1;
        val2 = red/val1;
    }
    
    int temp;
    if (max(val1, val2) != val1)
        swap(val1, val2);
    vector<int> answer;
    answer.push_back(val1+2);
    answer.push_back(val2+2);
    return answer;
}