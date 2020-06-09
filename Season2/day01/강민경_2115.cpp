#include <iostream>
#include <vector>
using namespace std;
 
int ans;
int n, m, c;
int honey[10][10];
bool check[10][10];
vector<int> workers[2];
 
 
//선택한 벌통에서 벌꿀을 채취한다. (sum은 벌통에 들은 꿀의 양, result는 꿀의 양을 제곱해서 얻는 수익)
int selectHoney(int worker,int index, int sum, int result) {
    //채취할 수 있는 최대 양 c를 넘어간 경우 불가능하므로 -1을 리턴
    if (sum > c) return -1;
 
    //m개의 벌통에 대해서 꿀을 채취할지 말지 모두 정해졌다.
    if (index == m) {
        return result;
    }
 
    //제곱한 결과
    int newresult = workers[worker][index] * workers[worker][index];
 
    int rt = 0;
 
    //index번째 벌통에서 꿀을 채취하는 경우
    int tmp1 = selectHoney(worker, index + 1, sum + workers[worker][index], result+newresult);
 
    //index번째 벌통에서 꿀을 채취하지 않는 경우
    int tmp2 = selectHoney(worker, index + 1, sum, result);
    
    //위 의 두가지 경우가 -1이 아니라면 더 작은 값을 리턴해준다.
    if (tmp1 != -1) rt = tmp1;
    if (tmp2 != -1 && rt < tmp2) rt = tmp2;
 
    return rt;
}
 
 
//두명의 일꾼이 벌통을 가로로 m개만큼 선택한다.
void solve(int index, int x) {
    //일꾼 두명 모두 선택이 끝났다.
    if (index > 1) {
        //두 일꾼의 벌통에서 꿀을 채취한다.
        int tmp = selectHoney(0, 0, 0, 0) + selectHoney(1, 0, 0, 0);
        if(ans < tmp) ans = tmp;
        return;
    }
 
    for (int i = x; i < n; i++) {
        for (int j = 0; j <= n-m; j++) {
            
            //현재 칸으로부터 m개의 벌통을 선택할 수 있는지 검사
            bool flag = true;
            for (int k = j; k < j + m; k++) {
                if (check[i][k]) {
                    flag = false;
                    break;
                }
            }
            //선택할 수 없다면 다음 칸으로 넘어간다.
            if (!flag) continue;
 
 
            //m개의 칸에 선택 표시를 하고 index번째 일꾼의 벌통에 넣는다.
            for (int k = j; k < j + m; k++) {
                check[i][k] = true;
                workers[index].push_back(honey[i][k]);
                
            }
 
            //다음일꾼의 경우를 탐색
            solve(index+1, i);
 
 
            //위의 탐색에서 돌아왔다면 다음 경우를 위해서 표시를 false로 바꿔주고 벡터에서도 빼준다.
            for (int k = j; k < j + m; k++) {
                check[i][k] = false;
                workers[index].pop_back();
            }
 
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        ans = 0;
        cin >> n >> m >> c;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> honey[i][j];
                check[i][j] = false;
            }
        }
 
        solve(0,0);
 
        cout << '#' << tc << ' ' << ans << '\n';
    }
 
    return 0;
}
