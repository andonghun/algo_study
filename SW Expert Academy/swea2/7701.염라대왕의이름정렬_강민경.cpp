#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
 
using namespace std;
bool lengthCheck(string s1, string s2){
     
    // 1. s1 == s2일때만 s1, s2길이를 비교해서 t/f 반환
    if(s1.length() == s2.length()){
        return s1 < s2;
    }else{ // s1이 s2보다 길이가 작으면 t, 
        return s1.length() < s2.length();
    }
}
int main(){
    ios::sync_with_stdio(false); 
    setbuf(stdout, NULL); 
    cin.tie(NULL);
    cout.tie(NULL);
     
    int testcase;
    int n;
    string name;
    vector<string> str;
       
    cin >> testcase ;
    for(int i=1; i<=testcase; i++){
        // 입력
        str.clear();
        cin >> n ;
        for(int j=0; j<n; j++){
            cin >> name;
            str.push_back(name);
        }
         
        // 1. sort 정렬을 사용해서 정렬
        // 단 배열의 길이가 작은 것부터 정렬하는 lengthCheck를 함
        sort(str.begin(), str.end(), lengthCheck);
        str.erase(unique(str.begin(), str.end()), str.end());
     
        int size = str.size();
        cout << "#" << i << "\n";
        for(int j=0; j<size; j++){
            cout << str[j] << "\n";
        }
                 
    }
     
    return 0;
}
