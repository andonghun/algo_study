#include <iostream>
#include <vector>
using namespace std;

int N, K;
int arr[21];
int cnt = 0;

void goSum(int sum, int idx) {

	if (sum > K || idx == N) {
		if (sum == K) {
			cnt++;
		}
		return;
	}

	goSum(sum + arr[idx], idx+1);
	goSum(sum, idx+1);
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_case;

	cin >> test_case;

	for (int t = 1; t <= test_case; t++){
		cin >> N >> K;

		for (int i = 0; i < N; i++) {			
			cin >> arr[i];
		}
		goSum(0, 0);
		cout << "#" << t << " "<< cnt << "\n";
		cnt = 0;
	}

	return 0;
}
