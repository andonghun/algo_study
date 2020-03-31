#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size();
    vector<char> temp;
    
    temp.push_back(number[0]);
    number = number.substr(1, number.length());
    
    // 맨 마지막을 나타내는 인덱스
    while(k > 0){
        if(temp.size() == 0){
            temp.push_back(number[0]);
            number = number.substr(1, number.length());
        }
        else if(temp.back() < number[0]){
            temp.pop_back();
            k--;
        }
        else if(temp.back() >= number[0]){
            if(number.size() <= number.size() - k) break; 
            temp.push_back(number[0]);
            number = number.substr(1, number.length());
        }
    }
    
    for(auto i:temp){
        answer.push_back(i);
    }
    
    answer.insert(answer.end(), number.begin(), number.end());
    
    if(answer.size() > size - k){
        answer.resize(size-k);
    }
    return answer;
}