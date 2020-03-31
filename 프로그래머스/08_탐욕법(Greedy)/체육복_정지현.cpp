#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> student(n,1);
    
    // 체육복을 잃어버렸을 경우
    for (int i = 0; i < lost.size(); i++) {
        student[lost[i]-1]--;
    }

    // 여벌의 체육복이 있을 경우
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i]-1]++;
    }
    
    for (int i = 0; i < n; i++) { 
    	// 여벌 체육복이 있는 학생의 경우
        if (student[i] > 1) {
            if (i != 0 && student[i-1] == 0) {
                student[i]--;
                student[i-1]++;
                continue;
            }
            
            if (i != n-1 && student[i+1] == 0) {
                student[i]--;
                student[i+1]++; 
        
            }        
        }
                
    }
    
    for (int i = 0; i < n; i++) {
        if (student[i] == 0) answer--;
    }
    
    return answer;
}