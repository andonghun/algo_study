#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
int N, M;

void dfs(int cnt){
    if(cnt == M){
        for(int i=0; i<answer.size(); i++){
			cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i=0; i<N; i++){
        answer.push_back(i+1);
        dfs(cnt + 1);
        answer.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    dfs(0);
    
    return 0;
}
