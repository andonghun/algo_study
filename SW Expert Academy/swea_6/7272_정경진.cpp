// SWEA 7272. 안경이 없어! (D3)
#include <iostream>
#include <string>

using namespace std;

char one[6] = {'A','D','O','P','Q','R'};

bool is_one(char c) {
    for (int i = 0; i < 6; i++) {
        if (one[i] == c)
            return true;
    }
    return false;
}

int get_hole_num(char c) {
    if (c == 'B')
        return 2;
    if (is_one(c))
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tcase = 1; tcase <= T; tcase++) {
        string a, b;
        cin >> a >> b;
        cout << "#" << tcase << " ";
        if (a.length() != b.length()) {
            cout << "DIFF\n";
            continue;
        }
        bool is_same = true;
        for (int i = 0; i < a.length(); i++) {
            if (get_hole_num(a[i]) != get_hole_num(b[i])) {
                cout << "DIFF\n";
                is_same = false;
                break;
            }
        }
        if (is_same)
            cout << "SAME\n";
    }
    return 0;
}
