// 반 만 맞음 ...ㅠ
#include <string>
#include <vector>
#include <stdio.h>
#define SIZE        26
#define UNICODE_A   65

using namespace std;
int alphabet[26];

int getMove(int alpha) {
    return alpha - UNICODE_A < 14 ? alpha - UNICODE_A : abs(SIZE - (alpha - UNICODE_A));
    // alpha - UNICODE_A : B이면 1이 나오고, A면 0이 나오고
    // A로부터 오른쪽으로 몇 칸 가 있는지
    // 왼쪽으로 알려면? Z면 -> 
    // 26개의 알파벳이 있으니까
    // 14번 부터는 거꾸로 도는 게 이득임
    // [1, 2, 3, 4, 5, 6, 7,(8),9,10] 배열 10개면 5부터는 거꾸로 도는게 이득인가?
    // 만약에 6이면 1이 되려면 5번임. 10/2 + 1 부터는 즉 6부터는 거꾸로 도는게 이득임
    // 따라서 알파벳은 26/2 + 1 인 14부터 거꾸로 도는게 이득
}

int solution(string name) {
    int answer = 0;
    int moveRight = name.length() - 1;
    
    for (int i = 0; i < SIZE; i++) {
        alphabet[i] = i + UNICODE_A;
        
    }
    
//     int count = 0;
//     for (int i=0; i<name.length(); i++) {
//         if (name[i] == 'A')
//             count++;
//     }
    
        
    for (int i=0; i<name.length(); i++) {
        
        if (name[i] == 'A')
            answer -= 1;
        printf("%d ", getMove(name[i]));
        answer += getMove(name[i]);
        
    }
    return answer + moveRight;
}

// 무슨 문제가 발생하냐면
// JAAB 이렇게 있으면 커서를 거꾸로 돌리는 것이 최소한임
// JAAB : 커서 1개 이득
// 그러면 AA가 연속해서 나오면 옆으로 돌리라고 하면 될까?
// 다른 경우 JBAAB 일 경우에는? -차이 없음
// 최초 스트링 이후에 A가 연속해서 나오는 경우만 처리해주기!!!
