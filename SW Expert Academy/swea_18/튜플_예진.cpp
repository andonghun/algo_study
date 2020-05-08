#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check[100000];

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    bool is_open = false;
    string t_string;
    vector<int> answer;
    vector<int> temp;
    vector<vector<int>> tuples;
    string::iterator iter;
    
    iter = s.begin();
	iter++; // 첫 번째 스킵
    
    for(; iter != s.end() - 1; iter++){
        if(*iter == '{'){
            is_open = true;
            continue;
        }
        else if(*iter == '}'){
            is_open = false;
            temp.push_back(stoi(t_string));
            if(!temp.empty()) tuples.push_back(temp);
            temp.clear();
            t_string.clear();
    	}
        else if(*iter == ',' && is_open == true){ // 괄호가 열린 상태에서의 콤마 인 경우
            temp.push_back(stoi(t_string));
            t_string.clear();
        }
        else if(*iter == ',') continue; // 괄호가 닫힌 상태에서의 콤마
        else{
            t_string.push_back(*iter);
        }
    }
    
    sort(tuples.begin(), tuples.end(), cmp);
    
    int curr;
    
    for(int i = 0; i < tuples.size(); i++){
        for(int j = 0; j < tuples[i].size(); j++){
            curr = tuples[i][j];
            if(check[curr] == false){
                answer.push_back(curr);
                check[curr] = true;
            }
        }
    }
    
    return answer;
}
