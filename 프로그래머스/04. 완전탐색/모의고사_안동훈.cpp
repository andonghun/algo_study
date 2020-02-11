#include <bits/stdc++.h>

using namespace std;

int max_f(int a, int b){
    if (a > b)
        return a;
    else 
        return b;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3,0);
    
    int supoja1[5] = {1,2,3,4,5};
    int supoja2[8] = {2,1,2,3,2,4,2,5};
    int supoja3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i < answers.size(); i++){
        if(supoja1[i % 5] == answers[i]) score[0]++; 
        if(supoja2[i % 8] == answers[i]) score[1]++;     
        if(supoja3[i % 10] == answers[i]) score[2]++;
    }
    //이부분 풀이를 봤습니다. 원래는 하나하나 배열 다 만들었는데 코어 오류어쩌고 저쩌고 해결 못함
    
    int temp = max_f(max_f(score[0],score[1]),score[2]);
    
    for (int i=0; i<3; i++){
        if(score[i] == temp) answer.push_back(i+1);
    }
    
    return answer;
}