#include <string>
#include <vector>

using namespace std;

int cnt;
int answer = -1;
int arr[8];

void dfs(int number, int num, int cnt) {
	if (cnt > 8) {
		return;
	}

	if (num == number) {
		if (cnt < answer || answer == -1) {
			answer = cnt;
		}
		return;
	}

	// 0 +-*/ 5 ... 0 +-*/ 55555555
	for (int i = 0; i < 8; i++) {
		int n = arr[i];
		dfs(number, num+n, cnt+i+1);
		dfs(number, num-n, cnt+i+1);
		dfs(number, num*n, cnt+i+1);
		dfs(number, num/n, cnt+i+1);
		
	}

}
int solution(int N, int number) {
	for (int i = 0; i < 8; i++) {
		arr[i] = (10 * i + 1) * N; // 5,55,555..
	}

    dfs(number, 0, 0);

    return answer;
}