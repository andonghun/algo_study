#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    int num = brown + red;
    for (int i = 3; i < brown; i++) {
         for (int j = 3; j < brown; j++) {
             if (i*j == num && i >= j) {
                if ((i-2) * (j-2) == red){
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
                
             }
         }
    }
}