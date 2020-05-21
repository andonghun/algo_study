#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (s < n) {
    	answer.push_back(-1);
    } else {
        answer.resize(n);
        int idx = 0;
    	while(n > 0) {
    		int num = s / n;
    		answer[idx] = num;
    		s -= num; 
            n--;
            idx++;
    	}
    }

    return answer;
}