#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	if (people.size() == 1) return 1;

	int answer = 0;
	sort(people.begin(), people.end());
	int i = 0, j = 0;

	// 몸무게가 큰 사람부터 더해가며 비교
    for (j = people.size()-1; j > i; j--) {
    	if (people[j] + people[i] <= limit) {
    		i++;
    		answer++;
    	} else {
    		answer++;
    	}
    }

    // 혼자 타는 경우
    if (i == j) answer++;

    return answer;
   	
}