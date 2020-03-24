// 7333. 한솔이의 택배 아르바이트
// 오답 41/200
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case;
	int T;
	int n;
	vector<int> weight;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		weight.clear();
		cin >> n;
		int data;
		int answer = 0;

		for (int i = 0; i < n; i++) {
			cin >> data;
			weight.push_back(data);
		}

		sort(weight.begin(), weight.end());

		while (!weight.empty()) {

			if (weight.back() >= 50) {
				answer++;
				weight.pop_back();
			}
			else {
				int count = 1;
				int size = weight.size();

				// 1. 나머지 모든 상자들을 다 합해도 50이 안될경우
				if (weight.back() * size < 50) {
					// 나머지 모든 원소들의 갯수만큼 무게를 곱했는데도 50kg가 안됨
				   // answer는 그대로, 지금 남은 무게 만큼 이전 계산할때 더해서 옮겨야함
                    weight.pop_back();
					break;
				}

				// 2. 나머지 상자들의 무게가 50이 넘는 상자의 갯수가 나올경우
				for (int i = 1; i <= size; i++) {
					if (weight.back() * i >= 50) {
						count = i;
					}
				}

				weight.pop_back();
				count--;
				while (count > 0) {
					weight.erase(weight.begin());
					count--;
				}
				answer++;

			} // end of else

		} // end of while

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
