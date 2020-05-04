#include<bits/stdc++.h>

using namespace std;

long long T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;

    for (long long i = 0; i < T; i++) {
        cin >> N;

        cout << "#" << i+1 << " " << (2 * (N-1) * (N - 1) + 1) << " " << (2 * (N - 1) * (N - 1) + 4 * (N - 1) + 1) << '\n';
    }

    return 0;
}
