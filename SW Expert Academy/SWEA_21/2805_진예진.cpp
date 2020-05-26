#include <stdio.h>

using namespace std;

int trees[1000000];
int N, M;

int cut(int meter_to_cut){
    int sum;
    for(int i = 0; i < N; i++){
        // printf("%d ", trees[i] - meter_to_cut);
        if(trees[i] >= meter_to_cut) sum += trees[i] - meter_to_cut; 
    }
    printf("sum: %d\n", sum);
    return sum;
}

int main(){
    int left, right, mid;
    FILE *stream = freopen("SWEA\\22\\2805_input.txt", "r", stdin);
    if(!stream) printf("freopen");

    scanf("%d %d", &N, &M);

    left = 0;
    right = 0;

    for(int i =0; i < N; i++){
        scanf("%d", &trees[i]);
        if(trees[i] > right) right = trees[i];
    }


    while(left < right){
        mid = (left + right) / 2;
        // printf("left: %d, right: %d mid: %d\n", left, right, mid);
        //printf("A");
        printf("mid: %d\n", mid);

        if(cut(mid) >= M){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d %d", right, left);
    return 0;
}
