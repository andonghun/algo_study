#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end()); // 진입 지점을 기준으로 오름차순
    int point = routes[0][1]; // 첫번째 차량이 고속도로를 나간 지점

    for (int i = 1; i < routes.size(); i++) {
    	if (routes[i][1] <= point) {
    		point = routes[i][1];
    	} else if (routes[i][0] > point) {
    		answer++;
    		point = routes[i][1];
    	}
    }

    return answer;
}