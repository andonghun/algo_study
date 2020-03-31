// 반 맞 맞음 ..ㅠㅠ
#include <string>
#include <vector>

using namespace std;

bool check[30] = {0, };


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int studentsWithUniform = n - lost.size();
    
    for (int i=0; i<reserve.size(); i++) {
        for (int j=0; j<lost.size(); j++) {
            if (!check[j]) {
                if (reserve[i] == lost[j]) {
                    check[j] = true;
                    break;  
                }
                if ((reserve[i]-1 == lost[j]) || reserve[i]+1 == lost[j]) {
                    answer++;
                    check[j] = true;
                    break;
                }
            }
        }
    }
    return answer + studentsWithUniform;
}
