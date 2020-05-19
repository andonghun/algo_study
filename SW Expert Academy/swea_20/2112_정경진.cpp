// 2112. [모의 SW 역량테스트] 보호 필름

#include <iostream>
#include <algorithm>

#define D_MAX 13
#define W_MAX 20
using namespace std;

int testcase;
int D, W, K, ans;
bool film[D_MAX][W_MAX];
bool tmp[D_MAX][W_MAX];
int key[14];

bool pass() {
    for (int i = 0; i < W; i++) {
        bool chk1 = false;
        for (int j = 0; j <= D - K; j++) {
            bool chk2 = false;
            for (int z = j + 1; z < j + K; z++) {
                if (tmp[j][i] != tmp[z][i]) {
                    chk2 = true; 
                    break;
                }
            }
            if (!chk2) {
                chk1 = true; // 그 열은 K개 이상 있음 표시
                break;
            }
        }
        if (!chk1) return false; // 한 열이라도 false이면 X
    }
    return true; // 모든 열이 K개 이상일 때만 true
}

void go(int row, int cnt) { // row : 약품을 주입하는 행, cnt : 약품 사용 횟수
    if (cnt >= ans) return;
    if (row == D) {
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                tmp[i][j] = film[i][j];
            }
        }
        for (int i = 0; i < D; i++) {
            if (key[i] != -1) {
                for (int j = 0; j < W; j++) {
                    tmp[i][j] = key[i];
                }
            }
        }
        if (pass())
            ans = min(ans, cnt);
    }
    if (row >= D) return;
    key[row] = -1; // 아무 약품도 주입하지 않았을 때
    go(row + 1, cnt);
    key[row] = 0; // A 약품 주입했을 때
    go(row + 1, cnt + 1);
    key[row] = 1; // B 약품 주입했을 때
    go(row + 1, cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        cin >> D >> W >> K;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> film[i][j]; // A = 0, B = 1
            }
        }
        ans = D;
        go(0, 0);
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
