#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int map[101][101];
int main() {
    int n;
    int x,y,d,g;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> y >> x >> d >> g;

        map[x][y] = 1;
        x += dx[d];
        y += dy[d]; 
        map[x][y] = 1;

        vector<int> dir;
        dir.push_back(d);

        while(g--) {
            int size = dir.size();
            for (int j = size-1; j >= 0; j--) {
                d = (dir[j]+1)%4; // 시계반대방향으로 90도 회전
                x += dx[d];
                y += dy[d]; 
            
                map[x][y] = 1;
                dir.push_back(d);
            }
        }

    }

    int cnt = 0;
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            if (map[i][j] == 1 && map[i][j+1] == 1 && 
                map[i+1][j] == 1 && map[i+1][j+1] == 1) {
                cnt++;
            }
        }
    }

    cout << cnt;
}
