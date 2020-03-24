// 1231. [S/W 문제해결 기본] 9일차 - 중위순회 (D4)
#include <iostream>

using namespace std;

struct Node {
    char val;
    int left;
    int right;
};

Node *nodes;

void in_order(int idx) {
    if (nodes[idx].left != -1)
        in_order(nodes[idx].left);
    cout << nodes[idx].val;
    if (nodes[idx].right != -1)
        in_order(nodes[idx].right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    for (int tcase = 1; tcase <= 10; tcase++) {
        int n; // node 개수
        int tmp;
        cin >> n;
        nodes = (Node*)malloc(sizeof(Node)*(n+1));

        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            cin >> nodes[i].val;
            
            if (n >= i*2)
                cin >> nodes[i].left;
            else nodes[i].left = -1;
            
            if (n > i*2)
                cin >> nodes[i].right;
            else nodes[i].right = -1;
        }
        cout << "#" << tcase << ' ';
        in_order(1);
        cout << '\n';
        free(nodes);
    }
    return 0;
}
