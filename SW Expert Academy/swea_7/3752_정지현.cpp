#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, score;
bool visited[10001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int T;
    cin>>T;

    for(int tc = 1; tc <= T; tc++) {
    	cin >> n;
        vector<int> v;
        memset(visited, false, sizeof(visited));

        /*
        0 : 0 .. [0]
        2 : 2 + 0 .. [0,2]
        3 : 3 + 0, 3 + 2 .. [0,2,3,5]
        5 : 5 + 0, 5 + 2, 5 + 3, 5 + 5 .. [0,2,3,5,7,8,10]
        */
        v.push_back(0);
        visited[0] = true;

        for (int i = 0; i < n; ++i) {  
            cin >> score;
                
            int size = v.size();
            for (int i = 0; i < size; ++i) {
                int num = v[i] + score; 
                if (!visited[num]) {
                    v.push_back(num);
                    visited[num] = true;
                }
            }
        }

        cout << "#" << tc << " " << v.size() << "\n";
        
    }
    
    return 0;
}