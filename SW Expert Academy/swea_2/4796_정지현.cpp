#include<iostream>

using namespace std;

int main(int argc, char** argv){
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		int n, answer = 0;
		
		cin >> n;

		bool flag = false; // true면 up, false면 down
		int up = 0;
		int down = 0;
		int prev;

		for (int i = 0; i < n; ++i){
			int next; cin >> next;

			if (i == 0) {
				prev = next;
				continue;
			} else if (i == 1) {
				if (prev < next) {
					flag = true;
					up++;
				} else if (prev > next) {
					flag = false;
					down++;
				}
			} else {
				if (flag && prev < next) {
					up++;
				} else if (!flag && prev > next) {
					down++;
				} else if (!flag && prev < next) { // 감소하고 있다가 다시 증가하면
					answer += up * down;
					flag = true;
					up = 1; down = 0;
				} else if (flag && prev > next) { // 증가하고 있다가 다시 감소하면
					flag = false;
					down++;
				}
			}

			prev = next;
		}
		
		if (up != 0 && down != 0) {
			answer += up * down;
		}

		printf("#%d %d\n", test_case, answer);

	}
	return 0;
}