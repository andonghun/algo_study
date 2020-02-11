#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for (int i = 123; i <= 987; i++) {
        string val = to_string(i);

        if (val[0] == '0' || val[1] == '0' ||val[2] == '0') {
            continue;
        }

        if (val[0] == val[1] || val[1] == val[2] || val[0] == val[2]) {
            continue;
        }

        bool flag = false;

        for (int j = 0; j < baseball.size(); j++) {
            int s = 0;
            int b = 0;

            string ball = to_string(baseball[j][0]);
            
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (ball[k] == val[l]) {
                        if (k==l) s++;
                        else b++;

                        break;
                    }
                }
            }

            if (s == baseball[j][1] && b == baseball[j][2]) {
                flag = true;
            } else {
                flag = false;
                break;
            }

        }

        if (flag) {
            answer++;
            //cout << val << endl;
        }

    }
    return answer;
}