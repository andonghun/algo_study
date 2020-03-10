#include<iostream>
#include <vector>
#include <stdio.h>
using namespace std;
 
int idx = 0;
vector<int> mountain;
vector<int> answer;
int T, N;
 
int search(int idx) {
    int cnt =0;
    int f1 = 0;
    int f2 = 0;
 
//  printf("------idx: %d\n", idx);
    for (int i = idx - 1; i >= 0; i--) {
        int temp = mountain[i + 1];
        if (mountain[i] < temp) {
//          printf("f1 idx: %d\n", i);
            f1++;
        }
        else break;
    }
 
    for (int i = idx + 1; i < N; i++) {
        int temp = mountain[i - 1];
        if (mountain[i] < temp) {
//          printf("f2 idx: %d\n", i);
            f2++;
        }
        else break;
    }
 
//  printf("f1 cnt : %d, f2 cnt : %d\n", f1, f2);
    cnt += f1 * f2;
    return cnt;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
 
    int test_case;
    cin.tie(0); cout.tie(0);
 
    scanf("%d\n", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d\n", &N);
        mountain.clear(); // 이거 안하면 idx값이 이상하게 들어감
 
        for (int i = 0; i < N; i++) {
            int data;
            scanf("%d", &data);
            mountain.push_back(data);
        }
         
        int ans = 0;
        for(int i=1; i< N-1; i++){
            if(mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1]){
                ans += search(i);
            }
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
 
     
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
