#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idx = 0;
    
    for (int i = 0; i < A.size(); i++) {
    	while(idx < B.size()) {
    		if (A[i] < B[idx]) {
    			answer++;
    			idx++;
    			break;
    		}
    		idx++;
    	}
    }
    
    return answer;
}