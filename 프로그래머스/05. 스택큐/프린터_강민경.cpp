#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> print; // 우선순위, idx
    
    vector<int> pr; // 우선순위 정렬을 위해 만든 벡터
    for(int i=0; i<priorities.size(); i++){
        print.push(pair<int,int>(priorities[i], i));
        pr.push_back(priorities[i]);
    }

    sort(pr.begin(), pr.end());
    int max = pr[pr.size()-1];;
    
    int cnt = 0;
    while(!print.empty()){
            
        for(int i=0; i<print.size(); i++){
            if(print.front().first != max){
                print.push(pair<int,int>(print.front().first, print.front().second));
                print.pop();
            }
            else{ // max == print.first
                cnt++;
                if(print.front().second == location){
                    answer = cnt;
                    return answer;
                }else{
                    pr.pop_back();
                    print.pop();
                    max = pr[pr.size()-1];
                }
            }
        }
    }
    
    return answer;
}
