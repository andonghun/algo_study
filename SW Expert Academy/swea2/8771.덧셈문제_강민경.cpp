/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); 
    long long testcase;
     
    scanf("%lld\n", &testcase);
    long long N, A, B;
    for(long long i=1; i<=testcase; i++){
        scanf("%lld %lld %lld\n", &N, &A, &B);
         
        printf("#%d ", i);
         
        if(A > B) printf("0\n"); // A는 작은수, B는 큰수
        else if(A == B) printf("1\n");
        else{
            if(N==1) printf("0\n"); 
            else if(N == 2) printf("1\n");
            else{
                if(A == B) printf("1\n");
                else{
                    long long min, max;
                    // 서로다른 숫자라는 명시가 없음
                    // 중복 가능한 숫자 일수도 있기 때문
                    // A가 최솟값, B가 최댓값이으로 가능한 수가
                    // A, A, A, A, .... B
                    // A, B, B, B,  .... B 일수도 있음
                    min = A * (N-1) + B ;
                    max = A + B*(N-1) ;
                     
                    printf("%lld\n", max-min+1);
                }
            }
        }
         
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}
