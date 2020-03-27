/*
2020-03-26 
3752 가능한 시험 점수
https://goodmilktea.tistory.com/50
*/
#include <iostream>
#include <cstring>


using namespace std;


int score[10000];
int numbers[100];
int result = 0;
int n;
 
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int T;
    FILE *stream;
 
    stream = freopen("SWEA\\7\\3752_input.txt", "r", stdin);

    if(!stream)
        printf("freopen");

    cin >> T;

    for(int testcase = 1; testcase <= T; testcase++) {
        memset(score, 0, sizeof(score));
        result = 0;
        cin >> n;
 
        score[0] = true;
        int max = 0;

        for(int i = 0; i < n; i++) {
            cin >> numbers[i];
            max += numbers[i];
            // 현재값을 더한 max 부터 감소하면서 탐색한다.
            // 만약 이전에 계산해둔 값이 있으면, 그 값에 현재 값을 더한다.
            for(int j = max; j >= 0; j--) {
                if(score[j]) {
                    score[j + numbers[i]] = true;
                }
            }
            // 꼭 위의 for문 이후에 true로 바꿔줘야함
            score[numbers[i]] = true;
        }
 
        for(int i = 0; i <= max; i++) {
            if(score[i]) result++;
        }
 
        cout <<"#"<<testcase<<" "<< result << endl;
    }
}
