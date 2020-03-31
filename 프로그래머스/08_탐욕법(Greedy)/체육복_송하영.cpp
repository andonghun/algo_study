#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool losted[32] = {false, };
    bool reserved[32] = {false, };
    for(int i = 0; i < lost.size();i++)
        losted[lost[i]] = true;
    for(int i = 0; i < reserve.size();i++)
        reserved[reserve[i]] = true;
    for(int i=1;i<=n;i++){
        if(!reserved[i])
            continue;
        if(losted[i])
            losted[i] = reserved[i] = false;
    }
    for(int i=1;i<=n;i++){
        if(!reserved[i])
            continue;
        if(losted[i-1]&&losted[i+1])
            continue;
        else if(losted[i-1])
            losted[i-1] = reserved[i] = false;
        else if(losted[i+1])
            losted[i+1] = reserved[i] = false;
    }
    for(int i=1;i<=n;i++){
        if(!reserved[i])
            continue;
        if(losted[i-1])
            losted[i-1] = reserved[i] = false;
        else if(losted[i+1])
            losted[i+1] = reserved[i] = false;
    }
    for(int i=1;i<=n;i++)
        if(losted[i])
            ++answer;
    
    return n-answer;
}
