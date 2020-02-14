#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int sum = 0;
    
    for (int i = 0; i < truck_weights.size(); i++) {
        int truck = truck_weights[i];
        
        while(1) {
            if (bridge.empty()) {
                bridge.push(truck);
                sum += truck;
                answer++;
                break;
            } else if (bridge.size() == bridge_length) {
                sum -= bridge.front();
                bridge.pop();
            } else {
                if (sum + truck > weight) {
                    bridge.push(0);
                    answer++;
                } else {
                    bridge.push(truck);
                    sum += truck;
                    answer++;
                    break;
                }
            }
           
        }
    }
    
    return answer + bridge_length;
}