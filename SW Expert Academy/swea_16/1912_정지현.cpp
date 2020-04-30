#include<iostream>
#include<algorithm>

using namespace std;

int dp[100001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> dp[i];
	}
	
	int answer = dp[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i-1] + dp[i], dp[i]);
		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;
}