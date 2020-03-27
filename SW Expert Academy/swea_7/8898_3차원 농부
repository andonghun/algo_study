/*
SWEA 8898.3차원 농부
2020-03-25 진예진
틀렸음
문제 링크 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW45TzHae8UDFAQ7&categoryId=AW45TzHae8UDFAQ7&categoryType=CODE
코드 참고 https://www.acmicpc.net/blog/view/25
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// M 소, N 말
int M, N;
int c1, c2;

struct Livestock{
    int x, z;
    Livestock(){}
    Livestock(int x, int z) :x(x), z(z){}
    bool operator < (const Livestock &v) const{
        if(z == v.z){
            return x < v.x;
        }else{
            return z < v.z;
        }
    }
};

bool cmp(const Livestock &u, const Livestock &v){
    return u.x < v.x;

}

int dist(Livestock a, Livestock b){
    return abs(b.x - a.x) + abs(b.z - a.z);
}

int main(void){
    int T;
    FILE *stream;

    stream = freopen("SWEA\\7\\8898_input.txt", "r", stdin);

    if(!stream)
        printf("freopen");

    scanf("%d", &T);

    for(int testcase = 1; testcase <= T; testcase++){
        scanf("%d %d", &N, &M);
        scanf("%d %d", &c1, &c2);
        
        vector<Livestock> livestock(N + M);

        for(int i = 0; i < N; i++){
            livestock[i].x = c1;
            scanf("%d", &livestock[i].z);
        }

        for(int i = N; i < N + M; i++){
            livestock[i].x = c2;
            scanf("%d", &livestock[i].z);
        }

        sort(livestock.begin(), livestock.end(), cmp);
/*
        for(auto x:livestock){
            printf("%d %d\n", x.x, x.z);
        }
        */

        set<Livestock> candidate = {livestock[0], livestock[1]};
        int ans = dist(livestock[0], livestock[1]);
        int start = 0;
        
        for(int i = 2; i < N+M; i++){
            Livestock now = livestock[i];
            while(start < i){
                auto p = livestock[start];
                int x = abs(now.x - p.x);
                if(x > ans){
                    candidate.erase(p);
                    start +=1;
                }else{
                    break;
                }
            }
            auto lower_point = Livestock(-1000000, now.z-ans);
            auto upper_point = Livestock(-1000000, now.z+ans);
            auto lower = candidate.lower_bound(lower_point);
            auto upper = candidate.upper_bound(upper_point);

            for(auto it = lower; it != upper; it++){
                int d = dist(now, *it);
                if(d < ans){
                    ans = d;
                }
            }
            candidate.insert(now);
        }
        printf("%d\n", ans);
    }
    return 0;
}
