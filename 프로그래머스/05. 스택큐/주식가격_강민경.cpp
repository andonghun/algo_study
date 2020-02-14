#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st; // prices의 idx 번호를 가진 스택
    
    for(int i=0; i<size; i++){
        // 스택에 저장된 idx값으로 prices[idx]와 현재 prices[i] 비교후
        // 현재 prices[i]가 작으면 (= 감소했으면)
        // pop한다
        while(!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        // 스택이 비었거나 prices[i]가 더 크면 idx를 st에 push
        st.push(i);
    }
    
    while(!st.empty()){
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}
