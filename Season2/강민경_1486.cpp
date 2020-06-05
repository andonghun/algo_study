#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int testcase;
int n,b,ans;
int a[21];

void dfs(int cnt,int height){
    if(cnt == n){
        if(height >= b)
            ans = min(ans,height);
        return;
    }
    
    dfs(cnt+1,height+a[cnt]);
    dfs(cnt+1,height);
}

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> testcase;
    for(int tc=1; tc<=testcase; tc++){
        // 입력
        cin >> n >> b;
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        ans = 987654321;
        dfs(0,0);
        
        cout << "#" << tc << " " << ans - b << "\n";
    }
    
    return 0;
}
