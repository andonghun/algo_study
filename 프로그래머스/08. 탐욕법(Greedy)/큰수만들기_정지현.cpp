#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    if (number.length() == 1) return number;

    string answer = "";
    int n = number.length() - k;

    for (int i = n; i > 0; i--) {
        char mx = '0';
        int idx = 0;

        for (int j = 0; j <= number.length()-i; j++) {
            if (number[j] > mx) {
                mx = number[j];
                idx = j;

                if (mx == '9') break;
            }
        }

        answer += number[idx];
        number = number.substr(idx+1);

        // number의 길이가 추가해야하는 숫자의 갯수와 같을 때
        if (number.length() == i-1) {
            answer += number;
            break;
        }

    }

    return answer;
}