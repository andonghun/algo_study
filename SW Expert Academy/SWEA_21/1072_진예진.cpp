/*
2020-05-25
[백준 1072 게임] https://www.acmicpc.net/problem/1072
*/

#include <stdio.h>
#include <math.h>

using namespace std;


int main(){
    int left, mid, right, temp;
    float x, y;

    scanf("%f %f", &x, &y);

    int z = (int)((y / x) * 100);
    left = 0;
    right = 1000000000;

    while(left <= right){
        mid = (left + right) / 2;
        temp = (int)(((y + mid) / (x + mid)) * 100);
        printf("mid: %d, temp: %d\n", mid, temp);

        if(z >= temp){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    printf("%d", left);
    return 0;
}
