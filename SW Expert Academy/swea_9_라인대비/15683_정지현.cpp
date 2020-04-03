#include <iostream>

using namespace std;

struct CCTV {
    int x,y,type;
}; 
CCTV cc[8];
int size;
int map[8][8];
int n,m;
int dir[] = {0,4,2,4,4,1};
int answer;

void copyMap(int from[8][8], int to[8][8]) {
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
            to[j][k] = from[j][k];
        }
    }
}
void monitor(int d, CCTV cctv) {
    d %= 4;
    int nx,ny;
    // 북
    if (d == 0) {
        nx = cctv.x + 1; 
        while (nx < n) {
            if (map[nx][cctv.y] == 6) break;
            map[nx][cctv.y] = -1;
            nx++;
        }
    } 
    // 동
    else if (d == 1) {
        ny = cctv.y + 1;
        while (ny < m) {
            if (map[cctv.x][ny] == 6) break;
            map[cctv.x][ny] = -1;
            ny++;
        }
    } 
    // 남
    else if (d == 2) {
        nx = cctv.x - 1;
        while (nx >= 0) {
            if (map[nx][cctv.y] == 6) break;
            map[nx][cctv.y] = -1;
            nx--;
        }
    } 
    // 서
    else if (d == 3) {
        ny = cctv.y - 1;
        while (ny >= 0) {
            if (map[cctv.x][ny] == 6) break;
            map[cctv.x][ny] = -1;
            ny--;
        }
    }
}

void dfs(int idx) {
    if (idx == size) {
        int cnt = 0;

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (map[j][k] == 0) cnt++;
            }
        }

        answer = answer > cnt ? cnt : answer;

        return;
    }

    int tmp[8][8];
   
    int x = cc[idx].x;
    int y = cc[idx].y;
    int type = cc[idx].type;

    for (int i = 0; i < dir[type]; ++i) {
        copyMap(map, tmp);

        if (type == 1) {
            monitor(i, cc[idx]);
        } else if (type == 2) {
            monitor(i, cc[idx]);
            monitor(i+2, cc[idx]);
        } else if (type == 3) {
            monitor(i, cc[idx]);
            monitor(i+1, cc[idx]);
        } else if (type == 4) {
            monitor(i, cc[idx]);
            monitor(i+1, cc[idx]);
            monitor(i+2, cc[idx]);
        } else if (type == 5) {
            monitor(i, cc[idx]);
            monitor(i+1, cc[idx]);
            monitor(i+2, cc[idx]);
            monitor(i+3, cc[idx]);
        }

        dfs(idx+1);
        copyMap(tmp, map);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    answer = 987654321;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];

            if (map[i][j] > 0 && map[i][j] < 6) {
                cc[size].x = i;
                cc[size].y = j;
                cc[size].type = map[i][j];
                size++;
            }
        }
    }

    dfs(0);

    cout << answer;

    return 0;
}
 
