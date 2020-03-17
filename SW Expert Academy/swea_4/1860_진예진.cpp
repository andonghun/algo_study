/*
1860. 진기의 최고급 붕어빵
2020-03-17
진예진
*/
#include <stdio.h>  
#include <string>  
#include <vector>  


using namespace std;
  
int T;  
bool is_possible = true; // 붕어빵을 다 줄 수 있나  
int bongeo = 0; // 현재 붕어빵의 수  
int N, M, K;  // N: 사람 수, M: K 개의 붕어빵을 만들 때 지나는 시간
string answer;
vector<int> customers(11112, 0);
  
int main(void)  
{  
    FILE *stream;

    stream = freopen("SWEA\\4\\1860_sample_input.txt", "r", stdin);
    
    if(!stream)
        perror("freopen");

    scanf("%d", &T);  
  
    for (int i = 0; i < T; i++)  
    {  
        scanf("%d %d %d", &N, &M, &K);  
  

        int max_time = -1; // 손님이 가장 늦게 도착한 시각  

        // customers에 손님이 몇시에 도착하는지 t 값을 인덱스로 해서 값을 늘려준다.
        for (int j = 0; j < N; j++)  
        {  
            int time;  
            scanf("%d", &time);  
  
            if (max_time < time)  
                max_time = time;  
  
            customers[time]++;  
        }  

    
        for (int t = 0; t <= max_time; t++)  
        {  
            // M초 마다 붕어빵 생성  
            if (t != 0 && t % M == 0)  
                bongeo += K;  
    
            // t시각에 방문한 손님 수 만큼 붕어빵 수 감소  
            bongeo -= customers[t];  
    
            // 붕어빵이 없으면 바로 break
            if (bongeo < 0)  
            {  
                is_possible = false;  
                break;  
            }  
        }  
    
        answer = is_possible ? "Possible" : "Impossible";

        printf("#%d %s\n", i + 1, answer.c_str());  
    }  
  
    return 0;  
}  
