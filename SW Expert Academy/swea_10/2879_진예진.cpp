#include <stdio.h>
#include <vector>


using namespace std;

int main(void){
    int N, temp, count_done;
    vector<int> original(1001, 0);
    vector<int> difference(1001, 0);
    bool is_plus;
    int answer;
    FILE *stream;

    stream = freopen("SWEA\\10_LINE_2\\2879_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

    scanf("%d", &N);


    for(int i = 0; i < N; i++){
        scanf("%d", &original[i]);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        difference[i] = temp - original[i];
    }

    count_done = 0;
    answer = 0;

    int i = 0;

    while(i != N -1){
        if(difference[i] == 0){
            i++;
            continue;
        }
        is_plus = difference[i] > 0 ? true : false;
        answer++;
        for(int j = i; j < N; j++){
            if(difference[j] > 0 == is_plus){
                difference[j] += is_plus == true ? -1 : 1;
            }
            else{
                break;
                answer++;
            }
            if(j == N - 1){
                answer++;
            }
        }
    }
    printf("%d", answer);
    return 0;
}
