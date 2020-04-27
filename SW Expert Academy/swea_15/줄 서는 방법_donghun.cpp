//순열로 푸니까 시간 초과 떠서 다시 품
//참고: https://mystes.tistory.com/33
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    
    long long t = 1;
    
    for(int i=1; i<=n; i++){
        t *= i;
        people.push_back(i);
    }
    
    int max = n;
    int idx;
    k--;
    
    while(1){
        if(answer.size() == max) break;
        
        t /= n;
        n--;   
        
        idx = k/t;
        answer.push_back(people[idx]);
        people.erase(people.begin() + idx);
        k %= t;
    }
    
    return answer;
}

//시간 초과

#include <bits/stdc++.h>

using namespace std;

bool visit[21];
vector<int> t;
vector<int> answer;
long long k_count;

void dfs(int idx, int numberOfHuman, long long target){
    if(idx == numberOfHuman ){
        k_count++;
        if(k_count == target) answer = t;
        return;
    }
    
    for(int i=1; i<=numberOfHuman; i++){
        if(visit[i]) continue;
        visit[i] = true;
        t.push_back(i);
        dfs(idx+1, numberOfHuman, target);
        t.pop_back();
        visit[i] = false;
    }
}

vector<int> solution(int n, long long k) {
    
    dfs(0,n,k);
    
    return answer;
}
