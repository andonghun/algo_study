#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int i = 0, j = 0;
	sort(people.begin(), people.end());
    
	for (j = people.size()-1; j > i; j--) {
		if (people[j] + people[i] <= limit) {
			i++;
			answer++;
		}
		else {
			answer++;
		}
	}
	if (i == j)
		answer++;
	return answer;
}

// 이렇게 짜려다 실패
// int solution(vector<int> people, int limit) {
//     int answer = 0;
//     int sum = 0;
//     int size = people.size();
//     int temp;
//     sort(people.begin(), people.end(), greater<int>());
    
//     for (int i = 0; i < size; i++) {
//         if (people[i] > limit / 2) {
//             answer += size - i;
//             break;
//         }
//         sum += people[i];
//         if (sum < limit) {
//             if (sum + people[i] > limit) {
//                 answer
//             } 
//         }
//     }
//     return answer;
// }
