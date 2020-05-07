//https://programmers.co.kr/learn/courses/30/lessons/64065?language=cpp

#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    vector<int> t;
    bool flag = false;
    int temp[6] = { -1, -1, -1, -1, -1, -1 };
    int idx = 0;
    int v_idx = 0;

    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') {
            flag = true;
        }
        else if (s[i] == '}') {
            int number = 0;
            int f = 1;
            for (int k = 5; k >= 0; k--) {
                if (temp[k] != -1) {
                    number += temp[k] * f;
                    f *= 10;
                }
            }
            for (int k = 0; k < 6; k++) temp[k] = -1;
            idx = 0;
            flag = false;

            t.push_back(number);
            v.push_back(t);
            t.clear();
        }
        else if (s[i] == ',') {
            if (flag) {
                int number = 0;
                int f = 1;
                for (int k = 5; k >= 0; k--) {
                    if (temp[k] != -1) {
                        number += temp[k] * f;
                        f *= 10;
                    }
                }
                for (int k = 0; k < 6; k++) temp[k] = -1;
                idx = 0;
                t.push_back(number);
            }
        }
        else {
            temp[idx++] = (int) s[i] - '0';
        }
    }

    sort(v.begin(), v.end(), cmp);

    answer.push_back(v[0][0]);

    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            bool check = false;
            for (int k = 0; k < answer.size(); k++) {
                if (v[i][j] == answer[k]) check = true;
            }
            if (!check) answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}
