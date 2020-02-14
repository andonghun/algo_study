#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    int current;
    int size = heights.size();
    for(int i=0; i<size; i++){
        if(i ==0) answer.push_back(0);
        else{
            int j = i-1;
            for( ; j>=0; j--){
                current = heights[i];
                if(heights[j] <= current){
                    heights.pop_back();
                }else break;
            }
            
            j = j+1;
            if(j<0) j = 0;
            answer.push_back(j);
        }
    }
    return answer;
}
/*
vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    int current;
    for(int i = heights.size()-1; i>=0; i--){
        int j = i-1;
        
        current = heights[i];
        
        while(heights[i] <= current){ 
            j--;
        }
        j = j+1;
        
        if(j < 0)
            j =0;
        answer[i] = j;
        
    }
    return answer;
}
*/
