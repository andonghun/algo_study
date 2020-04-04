#include<bits/stdc++.h>

using namespace std;

bool check(string word){
    bool flag = true;
    for(int i=0; i<word.size(); i++){
        if(word[i] != word[i+1]){
            for(int j=i+2; j<word.size(); j++){
                if(word[i] == word[j]) flag = false;
            }
        }
    }
    
    return flag;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    int cnt = 0; 

    string S;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S;
        if(check(S)) cnt++;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
