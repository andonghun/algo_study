#include <vector>
#include <algorithm>
using namespace std;
int SIZE;
//정답이 아니나 정답으로 인정되는 코드
/*
 inline bool is_possible(vector<int>& rocks, int &stnd, int &n, int &dis){
 register int removed = 0, prev = 0, i;
 for(i=0;i<SIZE;i++)
 rocks[i]-prev<stnd ? ++removed : prev = rocks[i];
 
 return (dis-rocks[i])<dis ? (removed+1)<=n : removed<=n;
 }
 */
//정답코드

inline bool is_possible(vector<int>& rocks, int &stnd, int &n, int &dis){
    register int removed = 0, prev = 0, i;
    for(i=0;i<SIZE;i++)
        rocks[i]-prev<stnd ? ++removed : prev = rocks[i];
    
    return dis-rocks[i-1]<stnd ? ++removed<=n : removed<=n;
}
int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());
    SIZE = rocks.size();
    register int lo = 1, hi = distance, mid;
    while(lo+1<hi){
        mid = (lo+hi)>>1;
        is_possible(rocks,mid,n,distance) ? lo = mid : hi = mid ;
    }
    return is_possible(rocks,lo,n,distance) ? lo : hi;
}
