#include <stdio.h>

using namespace std;

long long trees[1000000];
long long N, M;

long long cut(int meter_to_cut){
    long long sum = 0;
    for(int i = 0; i < N; i++){
        if(trees[i] >= meter_to_cut) sum += trees[i] - meter_to_cut;
    }
    return sum;
}

int main(){
    long long left, right, mid;
    FILE *stream = freopen("SWEA\\22\\2805_input.txt", "r", stdin);
    if(!stream) printf("freopen");

    scanf("%lld %lld", &N, &M);

    left = 0;
    right = 0;

    for(int i =0; i < N; i++){
        scanf("%d", &trees[i]);
        if(trees[i] > right) right = trees[i];
    }


    while(left <= right){
        mid = (left + right) / 2;

        if(cut(mid) >= M){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%lld", right);
    return 0;
}
