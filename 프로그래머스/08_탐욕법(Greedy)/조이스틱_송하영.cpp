#include <string>
#include <memory.h>
#include <iostream>
using namespace std;
int max_move, len;
void DFS(int moved,bool visited[20],int idx){
    if(moved>=max_move)
        return;
    bool flag = true;
    visited[idx] = true;
    for(int i=0;i<=len;i++)
        if(!visited[i]){
            flag = false;
            break;
        }
    if(flag){
        max_move = moved;
        return ;
    }
    bool n_visited[20];
    memcpy(n_visited,visited,sizeof(n_visited));
    DFS(moved+1,n_visited,idx+1>len ? 0 : idx+1);
    memcpy(n_visited,visited,sizeof(n_visited));
    DFS(moved+1,n_visited,idx-1==-1 ? len : idx-1);
}
int solution(string name) {
    int answer = 0;
    bool visit[20] = {false, };
    for(int i=0;i<name.length();i++){
        answer += name[i]-'A' < 'A'-name[i]+26 ? name[i]-'A' : 'A'-name[i]+26;
        if(name[i]=='A')
            visit[i]=true;
    }
    max_move = len = name.length()-1;
    DFS(0,visit, 0);
    return answer + max_move;
}
