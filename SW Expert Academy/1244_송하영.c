#include <stdio.h>
#include <memory.h>

char buf[7], _buf[7];
int used[1000000][10];
int N, len;
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}
void DFS(int depth, char _buf[7]) {
    if (depth==N) {
        for (int i = 0; i < len; i++) {
            if (buf[i]>_buf[i]) return;
            else if (buf[i]<_buf[i]) {
                memcpy(buf, _buf, sizeof(buf));
                return;
            }
        }
        return;
    }
    int is_used = 0;
    for (int i = 0; i < len - 1; i++)
        is_used = is_used*10 + _buf[i]-'0';
    if (used[is_used][depth]) return;
    used[is_used][depth] = 1;
    for (int i = 0; i<len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            char n_buf[7];
            memcpy(n_buf, _buf, sizeof(n_buf));
            swap(n_buf[i], n_buf[j]);
            DFS(depth + 1, n_buf);
        }
    }
}
int main(int argc, char** argv) {
    register int tc=1;
    int T;
    scanf("%d",&T);
    for (; tc <= T;tc++) {
        len = 0;
        scanf("%s",buf);
        strlen(buf);
        scanf("%d",&N);
        memcpy(_buf, buf, sizeof(_buf));
        memset(used, 0, sizeof(used));
        DFS(0, _buf);
        printf("#%d %s\n",tc,buf);
    }
}
