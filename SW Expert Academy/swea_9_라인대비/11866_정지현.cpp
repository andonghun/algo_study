#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        q.push(i+1);
    }

    cout << "<";
    while(1) {
        for (int i = 0; i < k-1; ++i) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if (!q.empty()) cout << ", ";
        else break;
    }
    cout << ">";

    return 0;
}
 
