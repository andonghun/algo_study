#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    queue<int> moving;
    
    
    for(int i = 0; i < truck_weights.size(); i++){
        int truck = truck_weights[i];
        while(true){
            if(moving.empty()){
                moving.push(truck);
                current_weight += truck;
                answer++;
                break;
            }
            else if(moving.size() == bridge_length){
                current_weight -= moving.front();
                moving.pop();
            }
            else{
                if(current_weight + truck <= weight){
                    moving.push(truck);
                    current_weight += truck;
                    answer++;
                    break;
                }
                else{
                    moving.push(0);
                    answer++;	
                }
            }
        }
    }
    answer += bridge_length;
    return answer;
}