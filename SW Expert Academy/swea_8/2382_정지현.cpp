#include <iostream>
#include <vector>
using namespace std;
 
struct Node {
    int x;
    int y;
    int num;
    int dir;
};
 
int n, m, k;
int dx[] = {0,-1,1,0,0 };
int dy[] = {0,0,0,-1,1 };
int d[] = {0,2,1,4,3}; // 반대 방향
vector<int> map[101][101];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
 
    for (int tc = 1; tc <= T; tc++) {
        cin >> n >> m >> k;
 
        vector<Node> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
        }
 
        while (m > 0) {
            // 미생물 군집 위치 초기화
            for (int i = 0; i < k; i++) {
                if (v[i].num == 0) continue;
                map[v[i].x][v[i].y].clear();
            }

            // 미생물 군집 이동
            for (int i = 0; i < k; ++i) {
                if (v[i].num == 0) continue;

                v[i].x += dx[v[i].dir];
                v[i].y += dy[v[i].dir];
                map[v[i].x][v[i].y].push_back(i);
            }

            for (int i = 0; i < k; ++i) {
                if (v[i].num == 0) continue;

                int x = v[i].x; 
                int y = v[i].y;
                
                // 약품에 도착했을 시
                if (x == 0 || x == n-1 || y == 0 || y == n-1) {
                    v[i].num /= 2;
                    v[i].dir = d[v[i].dir];
                } 
                
                // 두 개 이상 군집이 한 셀에 모일경우
                else if (map[x][y].size() > 1) {
                    int max_idx;
                    int max_dir;
                    int max_num = 0;
                    int sum = 0;

                    for (int i = 0; i < map[x][y].size(); ++i) {
                        int idx = map[x][y][i];
                        sum += v[idx].num;
                        if (v[idx].num > max_num) {
                            max_num = v[idx].num;
                            max_idx = idx;
                            max_dir = v[idx].dir;
                        }
                        v[idx].num = 0; 
                    }

                    v[max_idx].num = sum;
                    v[max_idx].dir = max_dir;
                }
            }
            m--;
        }
 
        int answer = 0;
        for (int i = 0; i < k; i++) {
            answer += v[i].num;
        }

        cout << "#" << tc << " " << answer << "\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j].clear();
            }
        }
    }

    return 0;
}
 
