#include <string>
#include <vector>
#include <algorithm>

// https://sewonkimm.github.io/algorithm/2019/09/05/Cardgame.html 참고
using namespace std;

// d[i][j] = 왼쪽이 i, 오른쪽이 j 일때 최대 점수값
int d[2001][2001];

int size;
vector<int> L;
vector<int> R;

int go(int i, int j)
{
    // 종료 검사
    if (i == size || j == size)
    {
        return 0;
    }

    // memoization
    if (d[i][j] > 0)
    {
        return d[i][j];
    }

    d[i][j] = max(go(i + 1, j + 1), go(i + 1, j));

    if (R[j] < L[i])
    {
        d[i][j] = max(d[i][j], go(i, j + 1) + R[j]);
    }

    return d[i][j];
}

int solution(vector<int> left, vector<int> right)
{

    size = left.size();
    L = left;
    R = right;

    return go(0, 0);
}
/* 큐로  풀고 40점...


#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    queue<int> qu_left;
    queue<int> qu_right;
    
    for(int i= 0; i<left.size(); i++){
        qu_left.push(left[i]);
    }
    for(int i= 0; i < right.size(); i++){
        qu_right.push(right[i]);
    }
    
 //   for(int i=0; i<right.size(); i++){
   //     printf("right: %d\n", qu_right.front());
     //   qu_right.pop();
   // }
    while( !qu_left.empty() && !qu_right.empty()) {
        
        // 1. 오른쪽이 작을 경우 answer += right-> pop
        if(qu_left.front() > qu_right.front()){
            answer += qu_right.front();
            qu_right.pop();
            // 2. 오른쪽이 클 경우 left -> pop
        }else if(qu_left.front() < qu_right.front()){
            qu_left.pop();
        }else{// 3. 같을경우 둘다 pop
            qu_right.pop();
            qu_left.pop();
        }
    }
    return answer;
}

*/
