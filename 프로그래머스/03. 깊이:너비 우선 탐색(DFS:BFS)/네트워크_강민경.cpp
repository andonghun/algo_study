#include <string>
#include <vector>

using namespace std;
int visited[210] ={0,};

void dfs(int start, vector<vector<int>> computers, int n, int cnt){
    visited[start] = 1;
    
    for(int i=0; i<n; i++){
        if(visited[i] ==0 && computers[start][i] != 0){
            dfs(i, computers, n, cnt+1);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            answer++;
            dfs(i, computers, n, answer);
        }
    }
    
    return answer;
}
