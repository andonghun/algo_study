#include <string>
#include <vector>

using namespace std;

int visited[200];
int cnt;

void dfs (int i, int n, vector<vector<int>> computers) {
    visited[i] = 1;

    for (int j = 0; j < n; j++) {
        if(computers[i][j] == 1 && visited[j] != 1) {
            //cnt++;
            dfs(j,n,computers);
        }
            
    } 

}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] != 1) {
            answer++;
            dfs(i,n,computers);
        } 
        
    }

    return answer;
}