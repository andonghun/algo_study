#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	// 모든 경우
	for (int i = 123; i <= 987; i++) {

		// 문자열로 변환
		string arr = to_string(i);
		if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) continue;
		if (arr[0] == '0' || arr[1] == '0' || arr[2] == '0') continue;

		bool is_check = true;

		for (int j = 0; j < baseball.size(); j++) {
			int strike = 0, ball = 0;

			for (int p = 0; p < 3; p++) {
				for (int q = 0; q < 3; q++) {
					string num = to_string(baseball[j][0]);

					// strike
					if (p == q && arr[p] == num[q]) {
						strike++;
						continue;
					}
					else if (arr[p] == num[q]) {
						ball++;
						continue;
					}
				}
			} // p,q for 종료

			if (strike != baseball[j][1] || ball != baseball[j][2]) {
				is_check = false;
				break;
			}
		} // for baseball

		if (is_check) answer++;
	}

	return answer;
}
