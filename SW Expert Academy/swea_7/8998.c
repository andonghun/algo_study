#include <stdio.h>
#include <stdlib.h>
int H, min_dist, pairs, cur_dist, N;
int C[500000];
int ABS(int a){
    return a>0 ? a : -a;
}
int dist(int c, int z1, int z2){
    return c + ABS(z2-z1);
}
int compare(const void *A, const void *B){
    return *(int*)A > *(int*)B ? 1 : -1;
}
void binary_search(int H, int c){
    int mid, distl, distm, distr, l = 0, r = N;
    distl = dist(c,C[0],H);
    distm = dist(c,C[1],H);
    if(distl<distm){
        if(distl==min_dist) ++pairs;
        else if(distl<min_dist){
            min_dist = distl;
            pairs = 1;
        }
        return;
    }
    distr = dist(c,C[N-1],H);
    distm = dist(c,C[N-2],H);
    if(distr<distm){
        if(distr==min_dist) ++pairs;
        else if(distr<min_dist){
            min_dist = distr;
            pairs = 1;
        }
        return;
    }
    while(l+1<r){
        mid = (l+r)/2;
        distl = dist(c,C[mid-1],H);
        distm = dist(c,C[mid],H);
        distr = dist(c,C[mid+1],H);
        if(distl<distm && distm<distr) r = mid;
        else if(distl>distm && distm>distr) l = mid;
        else if(distl>distm && distm < distr){
            if(distm==min_dist) ++pairs;
            else if(distm<min_dist){
                min_dist = distm;
                pairs = 1;
            }
            return;
        }
        else if(distl==distm){
            int distll;
            if(mid>=2) distll = dist(c,C[mid-2],H);
            else distll = 987654321;
            if(distll>distl){
                if(distm==min_dist) pairs+=2;
                else if(distm<min_dist){
                    min_dist = distm;
                    pairs = 2;
                }
                return;
            }
            else
                r = mid;
        }
        else if(distm == distr){
            int distrr;
            if(mid<=N-3) distrr = dist(c,C[mid+2],H);
            else distrr = 987654321;
            if(distrr>distr){
                if(distm==min_dist) pairs+=2;
                else if(distm<min_dist){
                    min_dist = distm;
                    pairs = 2;
                }
                return;
            }
            else
                l = mid;
        }
    }
}
int main(void) {
    int M, tc = 0, T, c1, c2, c, i;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        scanf("%d %d",&c1,&c2);
        c = ABS(c2-c1);
        for(i = 0; i < N; ++i)
            scanf("%d",&C[i]);
        qsort(C,N,sizeof(int),compare);
        min_dist = 987654321; pairs = 0;
        while(M--){
            scanf("%d",&H);
            binary_search(H,c);
        }
        printf("#%d %d %d\n",++tc,min_dist,pairs);
    }
}
