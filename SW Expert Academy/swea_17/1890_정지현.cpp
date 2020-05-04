#include<iostream>

using namespace std;

int map[101][101];
long long dp[101][101];
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dp[i][j] == 0 || (i == n-1 && j == n-1)) continue;

			int jump = map[i][j];
			if (i+jump < n) {
				dp[i+jump][j] += dp[i][j];
			}
			if (j+jump < n) {
				dp[i][j+jump] += dp[i][j];
			}
		}
	}

	cout << dp[n-1][n-1];

	return 0;
}