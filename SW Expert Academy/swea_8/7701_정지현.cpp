#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
bool cmp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    } 
    return a.length() < b.length();
}
int main(void) {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
 
    for(int tc = 1; tc <= T; ++tc) {
        int n;
        cin >> n;
        vector<string> v(n);
 
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
 
        sort(v.begin(), v.end(), cmp);
         
        cout << "#" << tc << "\n";
         
        string prev = v[0];
        cout << prev << "\n";
 
        for (int i = 1; i < n; ++i) {
            if (v[i] == prev) continue;
        
            cout << v[i] << "\n";
            prev = v[i];
        }
 
    }
    return 0;
}