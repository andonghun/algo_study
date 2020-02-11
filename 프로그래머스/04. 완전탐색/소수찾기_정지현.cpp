#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1 ) return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;

}

bool checkNum(int num, string numbers) {
    bool flag = false;
    vector<int> visitied(numbers.length(), 0);

    while(num > 0) {
        int rest = num % 10;

        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] - '0' == rest && visitied[i] == 0) {
                visitied[i] = 1;
                flag = true;
                break;
            } else {
                flag = false;
            }
        }

        if (!flag) return false;
            
        num /= 10;
    }

    return true;

}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());

    for (int i = 1; i <= stoi(numbers); i++) {
        if (isPrime(i) && checkNum(i, numbers)) {
            answer++;
        }
        
    }

    return answer;
}