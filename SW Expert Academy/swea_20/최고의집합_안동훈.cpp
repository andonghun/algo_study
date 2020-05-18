#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if(s<n){
        answer.push_back(-1);
        return answer;
    }
    
    int t = s/n;
    int r = s%n;
    for(int i=0; i<n; i++){
        answer.push_back(t);
    }
    
    for(int i=0; i<r; i++){
        answer[n-1-i]++;
    }
    
    return answer;
}
