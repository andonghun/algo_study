#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) answer.push_back(-1);
    else {
        int q = s / n;
        int r = s % n;
        int pos = n - 1;
        answer.assign(n, q);
        for (int i = r; i > 0; i--) answer[pos--]++;
    }
    return answer;
}
