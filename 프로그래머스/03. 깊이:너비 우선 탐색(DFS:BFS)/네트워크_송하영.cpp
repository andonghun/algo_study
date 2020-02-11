#include <string>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visit[200];
    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++){
        if(!visit[i]){
            answer++;
            queue<int> q;
            q.push(i);
            visit[i] = true;;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int j=0;j<computers[cur].size();j++){
                    if(computers[cur][j]==1&&!visit[j]){
                        q.push(j);
                        visit[j] = true;
                    }
                }
            }
        }
    }
    return answer;
}
