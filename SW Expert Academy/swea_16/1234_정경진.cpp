// SWEA 1234. [S/W 문제해결 기본] 10일차 - 비밀번호 (D3)
#include <iostream>
#include <stack>
#include <string>
#define TESTCASE 10
using namespace std;

int main() {
    int len;
    string num;

    for (int tc = 1; tc <= TESTCASE; tc++) {
        stack <int> s;
        stack <int> s_rev;
        cin >> len >> num;
        for (int i = 0; i < len; i++) {
            if (s.empty()) s.push(num[i] - '0');
            else if (s.top() == (num[i] - '0')) s.pop();
            else s.push(num[i] - '0');
        }
        
        while (!s.empty()) {
            s_rev.push(s.top());
            s.pop();
        }

        cout << "#" << tc << " ";
        while (!s_rev.empty()) {
            cout << s_rev.top();
            s_rev.pop();
        }
        cout << "\n";
    }
    return 0;
}
