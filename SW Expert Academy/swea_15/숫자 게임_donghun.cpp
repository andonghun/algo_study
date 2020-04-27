#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int idx_a = 0;
    int idx_b = 0;
    
    int max_idx = A.size();
    
    while(1){
        
        if(B[idx_b] > A[idx_a]){
            idx_a++;
            idx_b++;
            answer++;
        }
        else
        {
            idx_a++;
        }
        
        if(idx_a == max_idx) break;
   
    }

    return answer;
}

//아주 직관적으로 시간 초과

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    while(1){
        if(A.empty() && B.empty()) break;
        if(B[0] > A[0]){
            B.erase(B.begin());
            A.erase(A.begin());            
            answer++;
        }
        else
        {
            A.erase(A.begin());
            B.pop_back();           
        }
    }

    return answer;
}
