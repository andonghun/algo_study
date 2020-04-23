#include <bits/stdc++.h>
using namespace std;

int arr[8];
bool visit[8];
int N, M;

void dfs(int idx, int cnt){
    if(cnt == M){
        for(int i=0; i<=7; i++){
            if(visit[i] == true){
            	cout << arr[i] << " ";
            }
        }
        cout << '\n';
        return;
    }
    
    for(int i=idx; i<=N-1; i++){
        if(visit[i] == true) continue;
        visit[i] = true;
        dfs(i + 1, cnt + 1);
        visit[i] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=0; i<=7; i++){
    	arr[i] = i + 1;
    }
    
    dfs(0, 0);
    
    return 0;
}
