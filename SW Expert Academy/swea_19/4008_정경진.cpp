// SWEA 4008. [모의 SW 역량테스트] 숫자 만들기
#include <iostream>
#include <algorithm>
#include <vector>

#define NUM_OPER 4
#define INF 100000001
using namespace std;

int testcase;
int N, min_ans, max_ans;
int oper[4]; // +, -, *, /
int num[12];

vector<int> selected;

void init() {
    cin >> N;
    for (int i = 0; i < NUM_OPER; i++) {
        cin >> oper[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
}

int operation() {
    int res = num[0];
    for (int i = 0; i < selected.size(); i++) {
        switch (selected[i]) {
        case 0:
            res += num[i+1];
            break;
        case 1:
            res -= num[i+1];
            break;
        case 2:
            res *= num[i+1];
            break;
        case 3:
            res /= num[i+1];
            break;
        default:
            break;
        }
    }
    return res;
}

void dfs(int cnt) {
    if (cnt == N - 1) { // 사용한 연산자 개수가 N-1
        int res = operation();
        min_ans = min(min_ans, res);
        max_ans = max(max_ans, res);
        return;
    }
    for (int i = 0; i < NUM_OPER; i++) {
        if (oper[i] > 0) {
            selected.push_back(i);
            oper[i] -= 1;
            dfs(cnt+1);
            oper[i] += 1;
            selected.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;

    for (int tc = 1; tc <= testcase; tc++) {
        init();
        min_ans = INF;
        max_ans = -INF;
        dfs(0);
        cout << "#" << tc << " " << max_ans - min_ans << "\n";
    }
    return 0;
}
